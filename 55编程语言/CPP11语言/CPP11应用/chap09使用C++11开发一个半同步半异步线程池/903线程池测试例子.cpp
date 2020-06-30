void TestThdPool()
{
	ThreadPool pool;
	pool.Start(2);

	std::thread thd1([&pool]
	{
		for (int i = 0; i < 10;i++)
		{
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId]
			{
				cout << "同步层线程1的线程ID：" << thdId << endl;
			});
		}
	});

	std::thread thd2([&pool]
	{
		for (int i = 0; i < 10; i++)
		{
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId]
			{
				cout << "同步层线程2的线程ID：" << thdId << endl;
			});
		}
	});

	this_thread::sleep_for(std::chrono::seconds(2));
	getchar();
	pool.Stop();
	thd1.join();
	thd2.join();
}