// �����嵥14.1 EmpRec ������ӿ�
// EmpR.h ͷ�ļ�
#include <afxdb.h> // ΢��˾�ļ�
class EmpRec :public Crecordset
{
public:
	EmpRec(CDatabase* pDatabase = NULL);

	// �ֶ� ��������
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