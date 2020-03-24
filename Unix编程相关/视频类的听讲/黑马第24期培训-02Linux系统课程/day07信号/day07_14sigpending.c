#include <stdio.h>
#include <unistd.h>
#include <singal.h>

int main()
{
	sigset_t pend��sigproc;  //sigproc�������ź�
	//���������źţ��ȴ����������ź�
	sigemptyset(&sigproc); //�����
	sigaddset(&sigproc, SIGINT);  //�Ӹ�CTRL+C���ź�
	sigaddset(&sigproc, SIGQUIT);
	//9���źŲ�������������Ҳ����ʹ��������һ��
	sigaddset(&sigproc, SIGKILL);
	//���������źż�
	sigprocmask(SIG_BLOCK, &sigproc, NULL);
	//ѭ��ȡδ���źż�����ӡ
	while (true)
	{
		sigpending(&pend);
		int i = 1;
		for (i = 1; i < 32; i++)
		{
			if (sigismember(pend, i) == 1)  //���źż�
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);
	}
	return 0;
}