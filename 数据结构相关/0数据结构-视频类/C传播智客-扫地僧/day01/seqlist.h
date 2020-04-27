/*
C璇█鎻忚堪=====銆嬬嚎鎬ц〃鐨勮璁′笌瀹炵幇
ADT鎶借薄灞? 銆奫鏁版嵁缁撴瀯(C璇█鐗?].涓ヨ敋鏁廮鍚翠紵姘?鎵弿鐗?pdf銆?p44椤?
浜虹敓璐㈠瘜搴撶Н绱?
*/
 
#ifndef _WBM_LIST_H_
#define _WBM_LIST_H_
 
typedef void List;
typedef void ListNode;
 
//鍒涘缓骞朵笖杩斿洖涓€涓┖鐨勭嚎鎬ц〃
List* List_Create();
 
//閿€姣佷竴涓嚎鎬ц〃list
void List_Destroy(List* list);
 
//灏嗕竴涓嚎鎬ц〃list涓殑鎵€鏈夊厓绱犳竻绌? 绾挎€ц〃鍥炲埌鍒涘缓鏃剁殑鍒濆鐘舵€?
void List_Clear(List* list);
 
//杩斿洖涓€涓嚎鎬ц〃list涓殑鎵€鏈夊厓绱犱釜鏁?
int List_Length(List* list);
 
//鍚戜竴涓嚎鎬ц〃list鐨刾os浣嶇疆澶勬彃鍏ユ柊鍏冪礌node
int List_Insert(List* list, ListNode* node, int pos);  
 
//鑾峰彇涓€涓嚎鎬ц〃list鐨刾os浣嶇疆澶勭殑鍏冪礌
ListNode* List_Get(List* list, int pos);
 
//鍒犻櫎涓€涓嚎鎬ц〃list鐨刾os浣嶇疆澶勭殑鍏冪礌  杩斿洖鍊间负琚垹闄ょ殑鍏冪礌锛孨ULL琛ㄧず鍒犻櫎澶辫触
ListNode* List_Delete(List* list, int pos);
 
#endif
