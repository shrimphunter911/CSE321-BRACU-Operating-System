#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char email[127];
	printf("Enter email address: \n");
	scanf("%s", email);
	
	char *token = strtok(email, ".");
	token = strtok(NULL, " ");
	
	if (strcmp(token, "com")==0)
	{
		printf("Email address is outdated \n");
	}
	else if (strcmp(token, "xyz")==0)
	{
		printf("Email address is okay \n");
	}
	return 0;
}