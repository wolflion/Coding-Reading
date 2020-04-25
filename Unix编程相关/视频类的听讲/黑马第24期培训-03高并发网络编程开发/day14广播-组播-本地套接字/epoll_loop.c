/*
 * epoll鍩轰簬闈為樆濉濱/O浜嬩欢椹卞姩
 */
#include <stdio.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS  1024                                    //鐩戝惉涓婇檺鏁?#define BUFLEN      4096
#define SERV_PORT   8080

void recvdata(int fd, int events, void *arg);
void senddata(int fd, int events, void *arg);

/* 鎻忚堪灏辩华鏂囦欢鎻忚堪绗︾浉鍏充俊鎭?*/

struct myevent_s {
    int fd;                                                 //瑕佺洃鍚殑鏂囦欢鎻忚堪绗?    int events;                                             //瀵瑰簲鐨勭洃鍚簨浠?    void *arg;                                              //娉涘瀷鍙傛暟
    void (*call_back)(int fd, int events, void *arg);       //鍥炶皟鍑芥暟
    int status;                                             //鏄惁鍦ㄧ洃鍚?1->鍦ㄧ孩榛戞爲涓?鐩戝惉), 0->涓嶅湪(涓嶇洃鍚?
    char buf[BUFLEN];
    int len;
    long last_active;                                       //璁板綍姣忔鍔犲叆绾㈤粦鏍?g_efd 鐨勬椂闂村€?};

int g_efd;                                                  //鍏ㄥ眬鍙橀噺, 淇濆瓨epoll_create杩斿洖鐨勬枃浠舵弿杩扮
struct myevent_s g_events[MAX_EVENTS+1];                    //鑷畾涔夌粨鏋勪綋绫诲瀷鏁扮粍. +1-->listen fd


/*灏嗙粨鏋勪綋 myevent_s 鎴愬憳鍙橀噺 鍒濆鍖?/

void eventset(struct myevent_s *ev, int fd, void (*call_back)(int, int, void *), void *arg)
{
    ev->fd = fd;
    ev->call_back = call_back;
    ev->events = 0;
    ev->arg = arg;
    ev->status = 0;
    //memset(ev->buf, 0, sizeof(ev->buf));
    //ev->len = 0;
    ev->last_active = time(NULL);    //璋冪敤eventset鍑芥暟鐨勬椂闂?
    return;
}

/* 鍚?epoll鐩戝惉鐨勭孩榛戞爲 娣诲姞涓€涓?鏂囦欢鎻忚堪绗?*/

void eventadd(int efd, int events, struct myevent_s *ev)
{
    struct epoll_event epv = {0, {0}};
    int op;
    epv.data.ptr = ev;
    epv.events = ev->events = events;       //EPOLLIN 鎴?EPOLLOUT

    if (ev->status == 1) {                                          //宸茬粡鍦ㄧ孩榛戞爲 g_efd 閲?        op = EPOLL_CTL_MOD;                                         //淇敼鍏跺睘鎬?    } else {                                //涓嶅湪绾㈤粦鏍戦噷
        op = EPOLL_CTL_ADD;                 //灏嗗叾鍔犲叆绾㈤粦鏍?g_efd, 骞跺皢status缃?
        ev->status = 1;
    }

    if (epoll_ctl(efd, op, ev->fd, &epv) < 0)                       //瀹為檯娣诲姞/淇敼
        printf("event add failed [fd=%d], events[%d]\n", ev->fd, events);
    else
        printf("event add OK [fd=%d], op=%d, events[%0X]\n", ev->fd, op, events);

    return ;
}

/* 浠巈poll 鐩戝惉鐨?绾㈤粦鏍戜腑鍒犻櫎涓€涓?鏂囦欢鎻忚堪绗?/

void eventdel(int efd, struct myevent_s *ev)
{
    struct epoll_event epv = {0, {0}};

    if (ev->status != 1)                                        //涓嶅湪绾㈤粦鏍戜笂
        return ;

    epv.data.ptr = ev;
    ev->status = 0;                                             //淇敼鐘舵€?    epoll_ctl(efd, EPOLL_CTL_DEL, ev->fd, &epv);                //浠庣孩榛戞爲 efd 涓婂皢 ev->fd 鎽橀櫎

    return ;
}

/*  褰撴湁鏂囦欢鎻忚堪绗﹀氨缁? epoll杩斿洖, 璋冪敤璇ュ嚱鏁?涓庡鎴风寤虹珛閾炬帴 */
// 鍥炶皟鍑芥暟 - 鐩戝惉鐨勬枃浠舵弿杩扮鍙戦€佽浜嬩欢鏃惰璋冪敤
void acceptconn(int lfd, int events, void *arg)
{
    struct sockaddr_in cin;
    socklen_t len = sizeof(cin);
    int cfd, i;

    if ((cfd = accept(lfd, (struct sockaddr *)&cin, &len)) == -1) {
        if (errno != EAGAIN && errno != EINTR) {
            /* 鏆傛椂涓嶅仛鍑洪敊澶勭悊 */
        }
        printf("%s: accept, %s\n", __func__, strerror(errno));
        return ;
    }

    do {
        for (i = 0; i < MAX_EVENTS; i++)                                //浠庡叏灞€鏁扮粍g_events涓壘涓€涓┖闂插厓绱?            if (g_events[i].status == 0)                                //绫讳技浜巗elect涓壘鍊间负-1鐨勫厓绱?                break;                                                  //璺冲嚭 for

        if (i == MAX_EVENTS) {
            printf("%s: max connect limit[%d]\n", __func__, MAX_EVENTS);
            break;                                                      //璺冲嚭do while(0) 涓嶆墽琛屽悗缁唬鐮?        }

        int flag = 0;
        if ((flag = fcntl(cfd, F_SETFL, O_NONBLOCK)) < 0) {             //灏哻fd涔熻缃负闈為樆濉?            printf("%s: fcntl nonblocking failed, %s\n", __func__, strerror(errno));
            break;
        }

        /* 缁檆fd璁剧疆涓€涓?myevent_s 缁撴瀯浣? 鍥炶皟鍑芥暟 璁剧疆涓?recvdata */

        eventset(&g_events[i], cfd, recvdata, &g_events[i]);   
        eventadd(g_efd, EPOLLIN, &g_events[i]);                         //灏哻fd娣诲姞鍒扮孩榛戞爲g_efd涓?鐩戝惉璇讳簨浠?
    } while(0);

    printf("new connect [%s:%d][time:%ld], pos[%d]\n", 
            inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), g_events[i].last_active, i);
    return ;
}

// 鍥炶皟鍑芥暟 - 閫氫俊鐨勬枃浠舵弿杩扮鍙戠敓璇讳簨浠舵椂鍊欒璋冪敤
void recvdata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = recv(fd, ev->buf, sizeof(ev->buf), 0);            //璇绘枃浠舵弿杩扮, 鏁版嵁瀛樺叆myevent_s鎴愬憳buf涓?
    eventdel(g_efd, ev);        //灏嗚鑺傜偣浠庣孩榛戞爲涓婃憳闄?
    if (len > 0) {

        ev->len = len;
        ev->buf[len] = '\0';                                //鎵嬪姩娣诲姞瀛楃涓茬粨鏉熸爣璁?        printf("C[%d]:%s\n", fd, ev->buf);

        eventset(ev, fd, senddata, ev);                     //璁剧疆璇?fd 瀵瑰簲鐨勫洖璋冨嚱鏁颁负 senddata
        eventadd(g_efd, EPOLLOUT, ev);                      //灏唂d鍔犲叆绾㈤粦鏍慻_efd涓?鐩戝惉鍏跺啓浜嬩欢

    } else if (len == 0) {
        close(ev->fd);
        /* ev-g_events 鍦板潃鐩稿噺寰楀埌鍋忕Щ鍏冪礌浣嶇疆 */
        printf("[fd=%d] pos[%ld], closed\n", fd, ev-g_events);
    } else {
        close(ev->fd);
        printf("recv[fd=%d] error[%d]:%s\n", fd, errno, strerror(errno));
    }

    return;
}

// 鍥炶皟鍑芥暟 - 閫氫俊鐨勬枃浠舵弿杩扮鍙戠敓鍐欎簨浠舵椂鍊欒璋冪敤
void senddata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = send(fd, ev->buf, ev->len, 0);                    //鐩存帴灏嗘暟鎹?鍥炲啓缁欏鎴风銆傛湭浣滃鐞?    /*
    printf("fd=%d\tev->buf=%s\ttev->len=%d\n", fd, ev->buf, ev->len);
    printf("send len = %d\n", len);
    */

    if (len > 0) {

        printf("send[fd=%d], [%d]%s\n", fd, len, ev->buf);
        eventdel(g_efd, ev);                                //浠庣孩榛戞爲g_efd涓Щ闄?        eventset(ev, fd, recvdata, ev);                     //灏嗚fd鐨?鍥炶皟鍑芥暟鏀逛负 recvdata
        eventadd(g_efd, EPOLLIN, ev);                       //浠庢柊娣诲姞鍒扮孩榛戞爲涓婏紝 璁句负鐩戝惉璇讳簨浠?
    } else {
        close(ev->fd);                                      //鍏抽棴閾炬帴
        eventdel(g_efd, ev);                                //浠庣孩榛戞爲g_efd涓Щ闄?        printf("send[fd=%d] error %s\n", fd, strerror(errno));
    }

    return ;
}

/*鍒涘缓 socket, 鍒濆鍖杔fd */

void initlistensocket(int efd, short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(lfd, F_SETFL, O_NONBLOCK);                                            //灏唖ocket璁句负闈為樆濉?
    /* void eventset(struct myevent_s *ev, int fd, void (*call_back)(int, int, void *), void *arg);  */
    eventset(&g_events[MAX_EVENTS], lfd, acceptconn, &g_events[MAX_EVENTS]);

    /* void eventadd(int efd, int events, struct myevent_s *ev) */
    eventadd(efd, EPOLLIN, &g_events[MAX_EVENTS]);

    struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));                                               //bzero(&sin, sizeof(sin))
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);

	bind(lfd, (struct sockaddr *)&sin, sizeof(sin));

	listen(lfd, 20);

    return ;
}

int main(int argc, char *argv[])  //鍐欎簡涓猠poll妯″瀷
{
    unsigned short port = SERV_PORT;

    if (argc == 2)
        port = atoi(argv[1]);                           //浣跨敤鐢ㄦ埛鎸囧畾绔彛.濡傛湭鎸囧畾,鐢ㄩ粯璁ょ鍙?
    g_efd = epoll_create(MAX_EVENTS+1);                 //鍒涘缓绾㈤粦鏍?杩斿洖缁欏叏灞€ g_efd 
    if (g_efd <= 0)
        printf("create efd in %s err %s\n", __func__, strerror(errno)); //__func__鎵撳嵃褰撳墠鍑芥暟鍚嶇О

    initlistensocket(g_efd, port);                      //鍒濆鍖栫洃鍚瑂ocket

    struct epoll_event events[MAX_EVENTS+1];            //淇濆瓨宸茬粡婊¤冻灏辩华浜嬩欢鐨勬枃浠舵弿杩扮鏁扮粍   銆愯窡epoll_create鍒涘缓鐨勬暟鐩竴鏍枫€?	printf("server running:port[%d]\n", port);

    int checkpos = 0, i;
    while (1) {
        /* 瓒呮椂楠岃瘉锛屾瘡娆℃祴璇?00涓摼鎺ワ紝涓嶆祴璇昹istenfd 褰撳鎴风60绉掑唴娌℃湁鍜屾湇鍔″櫒閫氫俊锛屽垯鍏抽棴姝ゅ鎴风閾炬帴 */

        long now = time(NULL);                          //褰撳墠鏃堕棿
        for (i = 0; i < 100; i++, checkpos++) {         //涓€娆″惊鐜娴?00涓€?浣跨敤checkpos鎺у埗妫€娴嬪璞?            if (checkpos == MAX_EVENTS)
                checkpos = 0;
            if (g_events[checkpos].status != 1)         //涓嶅湪绾㈤粦鏍?g_efd 涓?                continue;

            long duration = now - g_events[checkpos].last_active;       //瀹㈡埛绔笉娲昏穬鐨勪笘闂?
            if (duration >= 60) {
                close(g_events[checkpos].fd);                           //鍏抽棴涓庤瀹㈡埛绔摼鎺?                printf("[fd=%d] timeout\n", g_events[checkpos].fd);
                eventdel(g_efd, &g_events[checkpos]);                   //灏嗚瀹㈡埛绔?浠庣孩榛戞爲 g_efd绉婚櫎
            }
        }

        /*鐩戝惉绾㈤粦鏍慻_efd, 灏嗘弧瓒崇殑浜嬩欢鐨勬枃浠舵弿杩扮鍔犺嚦events鏁扮粍涓? 1绉掓病鏈変簨浠舵弧瓒? 杩斿洖 0*/
        int nfd = epoll_wait(g_efd, events, MAX_EVENTS+1, 1000);  //鑾峰彇澶氬皯涓猣d
        if (nfd < 0) {
            printf("epoll_wait error, exit\n");
            break;
        }

        for (i = 0; i < nfd; i++) {
            /*浣跨敤鑷畾涔夌粨鏋勪綋myevent_s绫诲瀷鎸囬拡, 鎺ユ敹 鑱斿悎浣揹ata鐨剉oid *ptr鎴愬憳*/
            struct myevent_s *ev = (struct myevent_s *)events[i].data.ptr;  

            if ((events[i].events & EPOLLIN) && (ev->events & EPOLLIN)) {           //璇诲氨缁簨浠?                ev->call_back(ev->fd, events[i].events, ev->arg);
            }
            if ((events[i].events & EPOLLOUT) && (ev->events & EPOLLOUT)) {         //鍐欏氨缁簨浠?                ev->call_back(ev->fd, events[i].events, ev->arg);  //鍥炶皟鍑芥暟
            }
        }
    }

    /* 閫€鍑哄墠閲婃斁鎵€鏈夎祫婧?*/
    return 0;
}

