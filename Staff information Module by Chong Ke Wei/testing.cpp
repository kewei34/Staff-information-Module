#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
# pragma warning(disable:4996)

void main()
{
	char validation;
	int task;
	printf("%40s Please enter your choice:", "");
	scanf("%d%c", &task, &validation);
	while (/*isalpha(validation) != 0||*/isdigit(validation)==0&&validation!='\n')
	{
		//error();
		printf("\n%40s Please enter only digit!\n", "");
		printf("%40s Please enter your choice:", "");
		scanf("%d%c", &task, &validation);
	}
	system("pause");
}