#include <stdio.h>

int strlen_c(char *s);
char *strncpy_c(char *s, char *ct, int n);
char *strncat_c(char *s, char *ct, int n);
char *strncmp_c(char *s, char *ct, int n);

int main(void)
{
	char dest[] = "ABCDEF";
	char source[] = "GHIJ";

	strncpy_c(dest, source, 7);
	
	printf("copied string: %s\n", dest);

}

int strlen_c(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}


char *strncpy_c(char *s, char *ct, int n)
{
	int extra;
	for (; *ct && n > 0; --n) // Copy n times
		*s++ = *ct++;

	// Extra is everything we didn't copy. e.g *s = ABCDEF, *ct = GHIJ, n = 3 extra = DEF (3)
	for (extra = strlen_c(s) - n; extra > 0; extra--)
		*s++;

	*s = '\0'; // Add terminating char to the end
	
	return s;
}
