
//分块查找

typedef struct //定义索引表结构
{
	int key;  //关键字
	int ip;   //块起始记录的地址
}Index;

typedef struct //定义数据结构
{
	int key;//关键字
	float info;//数据信息
}DataList;


int blockSearch(DataList *data, int n, Index* index, int m, int k)
{
	//m为索引表长度，n为数据集每块长度
	int i = 0;
	int ip;
	while (k<index[i].key && i<m)
	{
		//在索引表中进行顺序查找，确定待比较关键字属于哪个块
		i++;
	}
	
	//获取块首记录的地址
	ip = index[i].ip;
	int endIp = ip + n;
	while (k!=data[ip].key && ip<endIp)
	{
		ip++;
	}

	if (ip == index[i+1].ip)
	{
		//未找到返回NULL
		return NULL;
	}
	//返回关键字的位置
	return ip;
}