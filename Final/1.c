#include <stdio.h>
#include <string.h>

int main() {
    char i[100];
    int j, sum;

    scanf("%[^\n]s", i);
    printf("The Vowels are\n");
    for (j=0; j<strlen(i); j++)
    {
        if (i[j] == 'a' || i[j] == 'e' || i[j] == 'i' || i[j] == 'o' || i[j] == 'u' || i[j] == 'A' || i[j] == 'E' || i[j] == 'I' || i[j] == 'O' || i[j] == 'U')
        {
        
        printf("%c\n", i[j]);
        sum= sum+i[j]; 
        }
    }
    printf("Sum of Vowels is: %d\n", sum);
    

    return 0;
}