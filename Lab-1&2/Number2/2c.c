#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{	
	int l, u, d, s;
	l=0;
	u=0;
	d=0;
	s=0;
	char pass[127];
	printf("Enter new password: \n");
	scanf("%s", pass);
	
	for(int i=0; i<strlen(pass); i++)
	{
		if (isupper(pass[i]))
		{
			u = 1;
			break;
		}
	}
	for(int i=0; i<strlen(pass); i++)
	{
		if (islower(pass[i]))
		{
			l = 1;
			break;
		}
	}
	for(int i=0; i<strlen(pass); i++)
	{
		if (isdigit(pass[i]))
		{
			d = 1;
			break;
		}
	}
	for(int i=0; i<strlen(pass); i++)
	{
		if ((pass[i]>=32 && pass[i]<=47) || (pass[i]>=58 && pass[i]<=64) || (pass[i]>=91 && pass[i]<=96) || (pass[i]>=123 && pass[i]<=126))
		{
			s = 1;
			break;
		}
	}
	if (u == 1 && l == 1 && d == 1 && s == 1)
	{
		printf("Ok \n");
	}
	if (u == 0)
	{
		printf("Uppercase Missing \n");
	}
	if (l == 0)
	{
		printf("Lowercase Missing \n");
	}
	if (d == 0)
	{
		printf("Digit Missing \n");
	}
	if (s == 0)
	{
		printf("Special Missing \n");
	}
	return 0;
}