
//�ֿ����

typedef struct //����������ṹ
{
	int key;  //�ؼ���
	int ip;   //����ʼ��¼�ĵ�ַ
}Index;

typedef struct //�������ݽṹ
{
	int key;//�ؼ���
	float info;//������Ϣ
}DataList;


int blockSearch(DataList *data, int n, Index* index, int m, int k)
{
	//mΪ�������ȣ�nΪ���ݼ�ÿ�鳤��
	int i = 0;
	int ip;
	while (k<index[i].key && i<m)
	{
		//���������н���˳����ң�ȷ�����ȽϹؼ��������ĸ���
		i++;
	}
	
	//��ȡ���׼�¼�ĵ�ַ
	ip = index[i].ip;
	int endIp = ip + n;
	while (k!=data[ip].key && ip<endIp)
	{
		ip++;
	}

	if (ip == index[i+1].ip)
	{
		//δ�ҵ�����NULL
		return NULL;
	}
	//���عؼ��ֵ�λ��
	return ip;
}