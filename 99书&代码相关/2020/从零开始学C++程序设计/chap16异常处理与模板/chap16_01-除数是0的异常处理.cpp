#include <iostream>
#include <cstdlib>
unsigned namespace std;

int main()
{
	cout << "==一个简单的例外范例==\n";
	//使用try...catch来捕获异常
	try
	{
		int n1;
		cout << "请输入除数：";
		cin >> n1;//请输入除数值
		if (n1==0)
		{
			throw 1;  //question：如果没有throw 1呢
		}
		cout << "没有捕获到例外" << endl;
	}
	catch (int i)
	{
		cout << "捕获到除数为0的例外" << endl;
	}
	//question：如果上面不写throw 1;  这里写个 catch(...){}会不会被提示
	cout << "结束程序的执行" << endl;

	system("pause");
	return 0;
	//这是默认的catch
#if 0
	catch (CMemoryException* e)
	{
		
	}
	catch (CFileException* e)
	{
	}
	catch (CException* e)
	{
	}
#endif
}