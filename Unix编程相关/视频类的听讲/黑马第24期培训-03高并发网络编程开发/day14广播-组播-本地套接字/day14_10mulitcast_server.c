#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>

int main(int argc, const char* argv[])
{
    //鍒涘缓濂楁帴瀛?
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if (fd == -1)
    {
        perror("socket error");
        exit(1);
    }
    //缁戝畾server鐨処P鍜岀鍙?
    struct sockaddr_in serv;
    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8787);//server鐨勭鍙?
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(fd,(struct sockaddr*)&serv, sizeof(serv));
    if(ret == -1)
    {
        perror("bind error");
        exit(1);
    }

    //鍒濆鍖栧鎴风鍦板潃淇℃伅
    struct sockaddr_in client;
    memset(&client,0,sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(6707);//瀹㈡埛绔缁戝畾鐨勭鍙?
    //浣跨敤缁勬挱鍦板潃缁欏鎴风鍙戞暟鎹?
    inet_pton(AF_INET,"239.0.0.10",&client.sin_addr.s_addr);

    //寮€鏀剧粍鎾潈闄?
    //int flag = 1;  //涓嶆槸int绫诲瀷浜嗭紝鑰屾槸in_addr绫诲瀷浜?
	struct ip_mreqn flag;
	//鍒濆鍖杅lag
	inet_pton(AF_INET, "239.0.0.10", &flag.imr_multiaddr.sin_addr);//缁勬挱鍦板潃
	inet_pton(AF_INET, "0.0.0.0", &flag.imr_address.s_addr);//鏈湴IP鍦板潃
	flag.imr_ifindex = if_nametoindex("ens33");//缃戝崱鐨勫湴鍧€锛?net/if.h>瑕佸姞杩欎釜澶存枃浠?
    setsockopt(fd,IPPROTO_IP,IP_MULTICAST_IF,&flag,sizeof(flag));


    //閫氫俊
    while(1)
    {
        //涓€鐩寸粰瀹㈡埛绔彂鏁版嵁
        static int num = 0;
        char buf[1024] = {0};
        sprintf(buf,"hello, udp == %d\n",num++);
        int ret = sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&client, sizeof(client));
        if(ret == -1)
        {
            perror("sendto error");
            break;
        }
        printf("server == send buf: %s\n",buf);

        sleep(1);
    }

    close(fd);
    return 0;
}
