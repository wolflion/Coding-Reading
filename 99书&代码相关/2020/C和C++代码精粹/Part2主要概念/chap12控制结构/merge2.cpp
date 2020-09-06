// 程序清单12.7 程序清单12.6的C++实现
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <list>
using namespace std;

const int BUFSIZE = 128;
struct FileInfo 
{
	ifstream *f;
	char line[BUFSIZE];
	FileInfo(char* fname)
	{
		f = new ifstream(fname);
		f->getline(line, BUFSIZE);
	}
	~FileInfo()
	{
		f->close();
		delete f;
	}
};

int main(int argc, char *argv[])
{
	string getNextLine(list<FileInfo*>&);
	//continued

	//打开文件：
	if (argc == 1)
	{
		return EXIT_FAILURE;
	}

	// 打开files-read首行：
	list<FileInfo*>flist;
	for (int i = 0; i < argc - 1;++i)
	{
		flist.push_back(new FileInfo(argv[i + 1]));
	}

	//做合并
	while (flist.size() > 0)
	{
		cout << getNextLine(flist) << endl;
	}

	return EXIT_SUCCESS;
}

string getNextLine(list<FileInfo*>& flist)
{
	// 按排序顺序查找下一行：
	char* next = "\xff";
	list<FileInfo*>::iterator small;
	list<FileInfo*>::iterator p = flist.begin();
	while (p != flist.end())
	{
		FileInfo* fp = *p;
		if (strcmp(next,fp->line) > 0)
		{
			small = p;
			next = fp->line;
		}
		++p;
	}

	// 提升相应的文件流到新行：
	FileInfo *fp = *small;
	ifstream* f = fp->f;
	char* line = fp->line;
	string minLine(line);
	f->getline(line, BUFSIZE);
	if (f->eof())
	{
		// 关闭并删除入口：
		delete fp;
		flist.erase(small);
	}

	//（不变式：每个flist入口仍有新行）
	return minLine;
}


ifstream f1(argv[1]);
ifstream f2(argv[2]);


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