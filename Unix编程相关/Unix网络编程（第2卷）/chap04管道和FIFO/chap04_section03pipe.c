#include "../unpipc_lionel.h"
void client(int, int);
void server(int, int);

int main(int argc, char* argv[])
{
	int pipe1[2], pipe2[2];
	pid_t childpid;

	pipe(pipe1);
	pipe(pipe2);

	if ((childpid = fork()) == 0)//child
	{
		close(pipe1[1]);  //书上为何要用包裹函数Close()？没看第1篇呢
		close(pipe2[0]);
		server(pipe1[0], pipe2[1]);
		exit(0);
	}
	//parent
	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0], pipe1[1]);

	waitpid(childpid, NULL, 0);//wait for child to terminate
	exit(0);
}