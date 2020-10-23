class TA
{
    public:
// 增加构造函数
      int &m_i;       // 引用就有问题，是main()中的引用，而不是拷贝。    问题1；
      TA(int &i):m_i(i) {}
      TA(TA &a):m_i(a.m_i) {}  //拷贝构造函数
      ~TA() {}
       void operator() () //不带参数
       {
           cout<<"operator start"<<endl;
           // 新增
           cout<<"m_i1的值"<<m_i<<endl;
       }
};

int main()
{
//新增
int myi=6;
TA tb(myi);
thread mythreadobj(tb);  
mythreadobj.detach();   // 主线程的结束后，`m_i`的变量被销毁了，所以子进程没有打印出来。【这就是个bug】，必须用join

TA ta;
thread mythreadobj(ta);  // ta是个可调用对象
mythreadobj.join(); // 等待子线程输出结束

mythreadobj.detach();  //如果用这个的话，可能会带来执行顺序有点乱的。

cout<<"a"<<endl;
}