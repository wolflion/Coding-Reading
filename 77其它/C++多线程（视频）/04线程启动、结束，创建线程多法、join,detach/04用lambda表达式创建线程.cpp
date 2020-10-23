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
auto mylamthread = []{
cout<<"a"<<endl;
cout<<"b"<<endl;
}

thread myobj3(mylamthread);
myobj3.join();

cout<<"a"<<endl;
}