#include <thread>

void func()
{
	printf("do some work");
}

void func_param(int i ,double d, const std::string& s)
{
	std::count << i << "," << d << "," << s << std::endl;
}

void func_sleep()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));//休眠3秒后，打印time out
	cout << "time out" << endl;
}

int join_test()
{
	std::thread t_join(func);
	t_join.join();
	return 0;
}

int detach_test()
{
	std::thread t_detach(func);
	t_detach.detach();
	//做其它事情
	return 0;
}


int join_test_param()
{
	std::thread t_join_param(func_param,1,2,"test");
	t_join_param.join();
	return 0;
}

int thread_info()
{
	std::thread t_info(func);
	cout << t_info.get_id() << endl;//获取当前进程的ID
	//获取CPU核数，如果获取失败则返回0
	cout << std::thread::hardware_concurrency() << endl;
	return 0;
}

int thread_sleep()
{
	std::this_thread t_sleep(func_sleep);
	t_sleep.join();
	return 0;
}

int main()
{
	join_test();
}