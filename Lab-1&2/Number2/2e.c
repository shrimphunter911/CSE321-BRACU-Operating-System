#include <stdio.h>

void isPalindrome(char* string)
{
	char *ptr, *rev;

	ptr = string;

	while (*ptr != '\0') {
		++ptr;
	}
	--ptr;

	for (rev = string; ptr >= rev;) {
		if (*ptr == *rev) {
			--ptr;
			rev++;
		}
		else
			break;
	}

	if (rev > ptr)
		printf("Palindrome \n");
	else
		printf("Not Palindrome \n");
}

int main()
{
	char str[1000];
	
	printf("Enter a string: \n");
	scanf("%s", str);
	
	isPalindrome(str);

	return 0;
}
