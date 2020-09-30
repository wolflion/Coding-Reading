// 程序清单14.1 EmpRec 结果集接口
// EmpR.h 头文件
#include <afxdb.h> // 微软公司文件
class EmpRec :public Crecordset
{
public:
	EmpRec(CDatabase* pDatabase = NULL);

	// 字段 参数数据
	// {AFX_FIELD(EmpRec, CRecordset)
	double m_ObjID;
	double m_DeptID;
	CString m_Name;
	CTime  m_HireDate;
	CString m_Job;
	double  m_MgrID;
	double m_Salary;
    //}} AFX_FIELD



	EmRec:public Crecordset();
	~EmRec:public Crecordset();

private:

};

EmRec:public Crecordset::EmRec:public Crecordset()
{
}

EmRec:public Crecordset::~EmRec:public Crecordset()
{
}