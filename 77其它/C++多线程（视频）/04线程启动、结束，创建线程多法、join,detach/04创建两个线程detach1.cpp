
#include <thread>
using namespace std;

//鑷繁鍒涘缓鐨勭嚎绋嬩篃瑕佷粠涓€涓嚱鏁板紑濮?
void myprint()
{
	// 鎴戣嚜宸辨兂鐨勶紝濡傛灉杩欎釜鍦版柟 sleep(60)
	cout<<"my thread start"<<endl;
	cout<<"my thread end"<<endl;
	cout << "my thread end1" << endl;
	cout << "my thread end2" << endl;
	cout << "my thread end3" << endl;
	cout << "my thread end4" << endl;
	cout << "my thread end5" << endl;
	cout << "my thread end6" << endl;
	cout << "my thread end7" << endl;
}

// 涓荤嚎绋嬩粠main()寮€濮嬫墽琛岋紝鎴戜滑鑷繁鍒涘缓鐨勭嚎绋嬶紝涔熼渶瑕佷粠涓€涓嚱鏁板紑濮嬭繍琛岋紙鍒濆鍑芥暟锛夛紝涓€鏃﹁繖涓嚱鏁拌繍琛屽畬姣曪紝灏变唬琛ㄧ潃鎴戜滑杩欎釜绾跨▼锛岃繍琛岀粨鏉熴€?
int main()
{
	thread mythreadobj(myprint);  // thread鏄爣鍑嗙被閲岀殑绫?  銆恗yprint鏄彲璋冪敤瀵硅薄銆?
	mythreadobj.detach();//璁╀富绾跨▼绛夊瓙杩涚▼鎵ц瀹屾瘯  銆愬綋瀛愮嚎绋嬫墽琛屽畬姣曪紝涓荤嚎绋嬪啀寰€涓嬭蛋銆?
	cout<<"I love china!"<<endl;
	
	return 0;
}