std::unique_lock<std::mutex> sbguard1(my_mutex1);
// **复制所有权是非法的**
std::unique_lock<std::mutex> sbguard2(my_mutex1);  //这样就相当于1个mutex与2个unique_lock绑定了。

//但可以转移
std::unique_lock<std::mutex> sbguard2(std::move(my_mutex1));


std::unique_lock<std::mutex> rtn_unique_lock()
{
	std::unique_lock<std::mutex> tmpguard(my_mutex1);
	return tmpguard;  //从函数返回一个局部的unique_lock对象是可以的。
	                  // 讲过移动构造函数
					  // 这种局部的tmpguard会导致系统生成临时的unique_lock对象，并调用unique_lock的移动构造函数
}

std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();