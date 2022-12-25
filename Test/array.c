#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int a[]= {10, 20, 30};
	int b[]= {40, 50};
	int x = sizeof(a)/sizeof(a[0]);
	int y = sizeof(b)/sizeof(b[0]);

	int c[x+y];
	for (int i=0; i<x; i++)
	{
		c[i]= a[i];
	}
	
	int j=x;
	int l=0;
	while (j<x+y)
	{
		c[j] = b[l];
		j++;
		l++;
	}
	
	//Test printing the array with loop
	for (int k=0; k<x+y; k++)
	{
		printf("%d \n", c[k]);
	}

	return 0;
}