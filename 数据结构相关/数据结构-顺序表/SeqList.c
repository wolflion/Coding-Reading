#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef char ElemType;

typedef struct  
{
	ElemType elem[MaxSize];
	int length;
}SqList;

void InitList(SqList *&L)    //鐢ㄥ埌浜?寮曠敤鐨勬蹇碉紝涓嶄簡瑙ｈ繖涓煡璇嗙偣鏃讹紝姝绘椿娌℃噦锛熴€愪笉鐢ㄥ紩鐢ㄧ殑璇濓紝鎬庝箞瑙ｅ喅鍛紵銆?
{
	L = (SqList *)malloc(sizeof(SqList));  //涓轰粈涔堝垎閰嶇殑鏄疞?鍙垎閰嶅埌澶寸粨鐐逛笂锛?
	L->length = 0;
}

void DestroyList(SqList *L)
{
	free(L);
}

int ListEmpty(SqList *L)  //涓轰綍涓嶇敤bool鍨嬶紵
{
	
	//if (L->length == 0)
		//return true;
	return(L->length == 0);  //杩欎釜杩斿洖鍟ュ憿锛?
}

int ListLength(SqList *L)
{
	return (L->length);
}

void DispList(SqList *L)
{
	//鎴戞病鏈夊垽绌?
	if (ListEmpty(L))
		return;

	for (int i = 0; i < L->length; i++)
	{
		printf("%c", L->elem[i]);
	}
	printf("\n");
}

//瀵硅繖绉嶅啓娉曪紝鎴戞湁鐤戦棶锛? 涓轰綍涓?ElemType GetElem(SqList *L, int i)
int GetElem(SqList *L, int i, ElemType &e)
{
	//娌℃湁鍒ゆ柇鏄惁瓒婄晫
	if (i<1 || i>L->length)
		return 0;
	e = L->elem[i-1];
	return 1;
}

ElemType GetElemByLionel(SqList *L, int i)  // 鏄负浜嗙敤寮曠敤锛岀渷浜嗕簺寮€閿€锛?
{
	//杩欐湁涓壇浣滅敤锛氬鏋滆秺鐣岋紝鎬庝箞鍒ゆ柇return鐨勬槸鍊硷紝杩樻槸瓒婄晫鎶ラ敊锛?
	return L->elem[i - 1];
}

//鏌ユ壘鍏冪礌
int LocateElemByLionel(SqList *L, ElemType e)
{
	if (ListEmpty(L))
		return 0; //杩斿洖0锛岃涔圠涓虹┖锛岃涔堟病鎵惧埌e

	for (int i = 0; i < L->length;i++)
	{
		if (e == L->elem[i])
		{
			return i + 1;
		}
		else
		{
			return 0;
		}
	}
}

// 浣滆€呯殑鏂瑰紡
int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i<L->length && L->elem[i]!=e)
	{
		i++;
	}

	if (i>=L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

// 鐢ㄤ簡寮曠敤锛岃繖涓繑鍥炲€肩被鍨嬫槸int锛岄兘鏈夌偣澶氫綑鍟婏紵銆愬湪椤圭洰涓紝杩斿洖鍊糹nt鏄湁鎰忎箟鐨勶紝鍙互鐢ㄥ畯鍚嶅畾涔夈€?
int ListInsert(SqList *&L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)  //鎻掑叆浣嶇疆涓嶅瓨鍦?
		return 0;
	i--;
	//杩欎釜涓嶉渶瑕乵alloc锛熶竴涓嬨€?
	for (j = L->length; j > i;j--) //浠庡悗寰€鍓嶆嫹璐濇暟鎹紝绌哄嚭涓€涓猧鐨勪綅缃?
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i] = e;
	L->length++;
	return 1;
}

int ListDelete(SqList* &L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L->length)
		return 0;

	i--;
	e = L->elem[i];  //杩欐牱灏辫兘鐭ラ亾锛岀i涓綅缃殑鍏冪礌鍊兼槸鍟ヤ簡
	// 鍓嶇Щ浜嗕竴涓厓绱?
	for (j = i; j < L->length;j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
	return 1;
}

int main()
{
	SqList *L;
	ElemType e;
	printf("锛?锛夊垵濮嬪寲椤哄簭琛↙\n");
	InitList(L);
	printf("锛?锛変緷娆￠噰鐢ㄥ熬鎻掓硶鎻掑叆a,b,c,d,e鍏冪礌\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("锛?锛夎緭鍑洪『搴忚〃\n");
	DispList(L);
	printf("锛?锛夐『搴忚〃L闀垮害=%d\n", ListLength(L));
	printf("锛?锛夐『搴忚〃L涓?s\n", (ListEmpty(L) ? "绌? : "闈炵┖"));
	GetElem(L, 3, e);
	printf("锛?锛夐『搴忚〃L鐨勭3涓厓绱?%c", e);
	ElemType tmp = GetElemByLionel(L, 3);
	printf("锛?锛夐『搴忚〃L鐨勭3涓厓绱?%c", tmp);
	printf("锛?锛夊厓绱燼鐨勪綅缃?%d\n", LocateElem(L, 'a'));
	printf("锛?锛夊厓绱燼鐨勪綅缃?%d\n", LocateElemByLionel(L, 'a'));
	printf("锛?锛夊湪绗?涓厓绱犱綅缃笂鎻掑叆f鍏冪礌\n");
	ListInsert(L, 4, 'f');
	printf("锛?锛夎緭鍑洪『搴忚〃L:");
	DispList(L);
	printf("锛?0锛夊垹闄鐨勭3涓厓绱燶n");
	ListDelete(L, 3, e);
	printf("锛?1锛夎緭鍑洪『搴忚〃L:");
	DispList(L);
	printf("锛?2锛夐噴鏀鹃『搴忚〃L\n");
	DestroyList(L);
}