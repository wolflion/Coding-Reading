// 没写出来，抄的网上的。
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string>result;
	string str;
	while(cin>>str)//直接略过空格
	{
		result.push_back(str);
	}
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		if(result[i][0]=='"')
		{
			cout<<result[i].substr(1,result[i].size()-1)<<endl;
		}
		else
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}

#if 0
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int iCount = 0;
	for (size_t i = 0; i < s.size();i++)
	{
		if (s[i] == ' ')
		{
			iCount++;
		}	
	}
	cout<<
}
#endif