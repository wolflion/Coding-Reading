#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void catch_sig(int num)
{
	printf("begin call ,catch %d sig\n", num);
	sleep(5);//Ϊ��ģ�Ⲷ����ִ��ʱ��ϳ�
	printf("end call ,catch %d sig\n", num);
}

int main()
{
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = catch_sig;
	sigemptyset(&act.sa_mask);

	//��ʱ����sa_mask  ���൱�� ��׽ʱ ����2���źš�
	sigaddset(&act.sa_mask, SIGQUIT);//��ʱ����ctr+\�ź�  ��������ִ�����ˣ���ָ�ԭ״����ִ��ctrl+\��

	//ע��һ�²�׽����
	sigaction(SIGINT, &act, NULL);
	while (true)
	{
		printf("who can kill me?\n");
		sleep(1);
	}
	return 0;
}

//kill 14 ����id��  ������һ�����ܲ�����źš�