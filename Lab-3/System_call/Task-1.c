#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	char buffer[100];
	FILE *fd;
	FILE *fp;
	int i = -1;
	while (i < 0)
	{
		printf("Enter a string: \n");
		scanf("%s", buffer);
		if (strcmp(buffer, "-1")==0)
		{	
			break;
		}
		else
		{	
			fd = fopen(argv[1], "a");
			fp = fopen(argv[2], "a");
			fprintf(fd, "%s \n", buffer);
			fprintf(fp, "Hello Anushua \n");
		}
	}
	return 0;
}