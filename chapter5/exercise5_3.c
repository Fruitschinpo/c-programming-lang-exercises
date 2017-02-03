#include <stdio.h>


void strcat_c(char *s, char *t);

int main(void)
{
	char string1[8192] = "hello";
	char string2[8192] = "there";
	
	printf("String1: %s\n", string1);
	printf("String2: %s\n", string2);

	strcat_c(string1, string2);
	printf("Strcat: %s\n", string1);

	return 0;

}

void strcat_c(char *s, char *t)
{
	while (*s != '\0') {
		*s++; // Go the the last char in s
	}
	while ((*s++ = *t++) != '\0') // copy t to the end of s
		;
}
