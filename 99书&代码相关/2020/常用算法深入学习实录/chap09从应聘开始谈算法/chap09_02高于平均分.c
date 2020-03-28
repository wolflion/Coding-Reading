#include "../head.h"

/*求高于平均分的学生 学号及成绩；
 * 学号和成绩人工输入
 */

double find(int total, int n)
{
	int number, score, average;
	scanf("%d", &number);
	if (number != 0)
	{
		scanf("%d", &score);
		average = find(total + score, n + 1);
		if (score>=average)
		{
			printf("%d:%d\n", number, score);
		}
		return average;
	}
	else
	{
		printf("Average=%d\n", total / n);
		return total / n;
	}
}

int main(int argc, char* argv[])
{
	find(0, 0);
}