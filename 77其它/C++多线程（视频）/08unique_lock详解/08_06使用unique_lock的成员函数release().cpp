

//相当于把sbguard1和my_mutex绑定在一起了
std::unique_lock<std::mutex> sbguard1(my_mutex);

std::mutex *ptx = sbguard1.release();//指针ptx，就是指向my_mutex【现在需要自己解锁】

msgRecvQueue.push_back(i);

ptx->unlock();//自己负责把mutex给unlock掉