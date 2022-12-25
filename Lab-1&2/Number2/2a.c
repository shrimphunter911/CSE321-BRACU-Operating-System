#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{	
	int c;
	c = a+b;
	return c;
}

int sub(int a, int b)
{	
	int c;
	c = a-b;
	return c;
}

int mul(int a, int b)
{	
	int c;
	c = a*b;
	return c;
}

int main(void)
{
	int a, b, c;
	char op[1];
	printf("Enter first number: \n");
	scanf("%d", &a);
	printf("Enter second number: \n");
	scanf("%d", &b);
	printf("Enter the operator: \n");
	scanf("%s", op);
	
	if (a>b)
	{
		if (strcmp(op, "-")==0)
		{
			printf("Result: %d\n", sub(a, b));
		}
	}
	else if (a<b)
	{
		if (strcmp(op, "+")==0)
		{
			printf("Result: %d\n", add(a, b));
		}
	}
	else if (a==b)
	{
		if (strcmp(op, "*")==0)
		{
			printf("Result: %d\n", mul(a, b));
		}
	}
	return 0;

}
	