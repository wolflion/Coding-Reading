/*
// 鎻忚堪锛?

杈撳叆涓€涓暣鏁帮紝灏嗚繖涓暣鏁颁互瀛楃涓茬殑褰㈠紡閫嗗簭杈撳嚭

绋嬪簭涓嶈€冭檻璐熸暟鐨勬儏鍐碉紝鑻ユ暟瀛楀惈鏈?锛屽垯閫嗗簭褰㈠紡涔熷惈鏈?锛屽杈撳叆涓?00锛屽垯杈撳嚭涓?

*/
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int iInput;
	cin >> iInput;

	stringstream ss;
	ss << iInput;
	string sValue = ss.str();
	for (size_t iLen = sValue.length(); iLen > 0; iLen--)
	{
		cout<<sValue[iLen-1];
	}

	//鏄庢槑鏈夎繖涓啓娉曠殑鍟?http://www.cplusplus.com/reference/string/string/cend/
#if 0
	for (auto it = sValue.cend(); it != sValue.cbegin(); ++it)
	{
		cout << *it;
	}
#endif
}