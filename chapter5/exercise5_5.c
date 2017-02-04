#include <stdio.h>

int strlen_c(char *s);
char *strncpy_c(char *s, char *ct, int n);
char *strncat_c(char *s, char *ct, int n);
int strncmp_c(char *cs, char *ct, int n);

int main(void)
{
	char dest[] = "ABCDEF";
	char source[] = "GHIJ";

	char comp1[] = "ABC";
	char comp2[] = "AB";

	strncpy_c(dest, source, 7);
	
	printf("copied string: %s\n", dest);


	strncat_c(dest, source, 4);
	
	printf("concated string: %s\n", dest);

	printf("strncmp: %d\n", strncmp_c(comp1, comp2, 2));

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

char *strncat_c(char *s, char *ct, int n)
{
	// move to the last char in *s
	while (*s != '\0')
		*s++;

	// Order of n and check for '\0' is important.
	// If the *s++ = *ct++ is done before checking n, then the string will add an char before knowing it's ok.
	for (;  n > 0 && ((*s++ = *ct++) != '\0'); --n)
		;

	*s = '\0'; // Add terminating char to the end
	return s;
}

int strncmp_c(char *cs, char *ct, int n)
{
	for ( ; n > 0 && *cs == *ct; *cs++, *ct++, --n) // While n is bigger than 0 and cs and ct share the same value
		if (*cs == '\0')
			return 0; // We've reached the end of both strings and they have all been equal, they are the same.
	return *cs - *ct; // Lexiographical return value
}
