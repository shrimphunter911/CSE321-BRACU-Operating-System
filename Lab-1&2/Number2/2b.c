#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *file;
	FILE *wr;
	char buff[255];

	file = fopen("2b.txt", "r");
	wr = fopen("2bOutput.txt", "a");

	fgets(buff,255,file);
	printf("%s \n", buff);
	fclose(file);

	char *token = strtok(buff, " ");
	while (token != NULL)
    	{	
		printf("%s \n", token);
		fprintf(wr, "%s ", token);
        	token = strtok(NULL, " ");
    	}

	return 0;
}