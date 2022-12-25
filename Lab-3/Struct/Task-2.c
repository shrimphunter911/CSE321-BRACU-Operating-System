#include <stdio.h>
#include <string.h>

struct Perfect
{
	int start;
	int end;
};
	
int isPerfect(int n)
{
	int sum, i;
	sum = 1;
	i = 2;
	
	while (i<n)
	{
		
		if (n%i==0)
		{
			sum = sum + i;
		}
		i += 1;
	}
	
	return sum;
}

int main()
{
	struct Perfect perfect;
	
	scanf("%d", &perfect.start);
	scanf("%d", &perfect.end);
	
	for(perfect.start; perfect.start<=perfect.end; perfect.start=perfect.start+1)
	{	if (perfect.start==1)
		{
		}
		else if (perfect.start==isPerfect(perfect.start))
		{
			printf("%d\n", perfect.start);
		}
	}
	return 0;
}