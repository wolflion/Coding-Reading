
class String
{
public:
	String(const char *str = NULL); //��ͨ���캯��
	String(const String &other);    //�������캯��
	~String();
	String & operator =(const String &other); //��ֵ��������������أ�
	String & operator +(const String &other); //�ַ�������
	bool operator ==(const String &other);    //�ж����
	int getLength();                          //���س���
private:
	char *m_data;  //˽�б��������ַ���
};