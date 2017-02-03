#include <stdio.h>

int strlen_c(char *s);
// Returns 1 if t is at the end of s, otherwise 0
int strend(char *s, char *t);
// Returns 0 if they are the same, <0 if s<t and >0 if s>t
int strcmp_c(char *s, char *t);


int main(void)
{
	char *string1 = "hello";
	char *string2 = "o";

	printf("Is t at the end of s? %d\n", strend(string1, string2));
}

int strlen_c(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}


int strend(char *s, char *t)
{
	int s_length = strlen_c(s);
	int t_length = strlen_c(t);

	if (t_length <= s_length) {
		s += s_length - t_length;
		if (strcmp_c(s, t) == 0) {
			return 1;
		}
	}
	return 0;
}

int strcmp_c(char *s, char *t)
{
	for ( ; *s == *t; *s++, *t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
