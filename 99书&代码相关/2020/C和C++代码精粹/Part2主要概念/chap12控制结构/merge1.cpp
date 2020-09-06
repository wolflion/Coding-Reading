// 程序清单12.5 程序清单12.3的C实现
#include <iostream>
#include <fstream>
#include <cstring>  // 为了应用strcmp()
#include <cstdlib>  // 为了应用EXIT代码
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
	const int BUFSIZE = 128;
	char buf1[BUFSIZE], buf2[BUFSIZE];

	//打开文件：
	if (argc != 3)
	{
		return EXIT_FAILURE;
	}
	ifstream f1(argv[1]);
	ifstream f2(argv[2]);

	//做合并
	f1.getline(buf1, BUFSIZE);
	f2.getline(buf2, BUFSIZE);
	while (f1 && f2)
	{
		// (不变式：两个缓冲器都有新行）

		// 打印和刷新适当的行：
		if (strcmp(buf1, buf2) <= 0)
		{
			cout << buf1 << buf2;
			f1.getline(buf1, BUFSIZE);
		}
		else
		{
			cout << buf2 << buf2;
			f2.getline(buf2, BUFSIZE);
		}
	}

	// （不变式：至少有一个文件已经读完）
	// 清空剩下的文件
	while (f1)
	{
		// （不变的：buf1有一个新行）
		cout << buf1 << endl;
		f1.getline(buf1, BUFSIZE);
	}
	assert(f1.eof());  // （不变式：file1已经读完）
	while (f2)
	{
		// （不变的：buf2有一个新行）
		cout << buf2 << endl;
		f2.getline(buf2, BUFSIZE);
	}
	assert(f2.eof());  // （不变式：file2已经读完）
	
	return EXIT_SUCCESS;
}