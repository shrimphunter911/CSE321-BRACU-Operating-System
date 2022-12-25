#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	FILE *fd;
	char b[100];
	
	fd = fopen("text.txt", "r");
	fscanf(fd, "%s", b);
	printf("%s\n", b);

	fgets(b, 100, (FILE*)fd);
	printf("%s\n", b);

	fgets(b, 100, fd);
	printf("%s\n", b);
}