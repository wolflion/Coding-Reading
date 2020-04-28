
class String
{
public:
	String(const char *str = NULL); //普通构造函数
	String(const String &other);    //拷贝构造函数
	~String();
	String & operator =(const String &other); //赋值函数（运算符重载）
	String & operator +(const String &other); //字符串连接
	bool operator ==(const String &other);    //判断相等
	int getLength();                          //返回长度
private:
	char *m_data;  //私有变量保存字符串
};