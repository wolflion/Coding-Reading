#include <stdio.h>
#include <unistd.h>

int main()
{
	//int execlp(const char *file, const char *arg,  .../* (char  *) NULL */); 
	// file �ǽ�����������������arg���ǽ��̵Ĳ�������Ҫ��agrv[0]��ʼ��

	//execlp("ls", "ls", "-l", NULL);
	execlp("ls", "ls", "-l","--color=auto" NULL);  // ����л���������


	// execl
	execl("/bin/ls", "ls", "-l", "--color=auto" NULL);   // ����ִ��Ч����һ����
	//����Ҫ�жϷ���ֵ
	perror("execlp err");

	printf("hello \n");
	return 0;
}