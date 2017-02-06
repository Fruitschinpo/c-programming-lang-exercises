// Sorting program from the C-programming language by K&R

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000


static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


char *lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN];

int my_readlines(char lines[][MAXLEN], int nlines);
void writelines(char lines[][MAXLEN], int nlines);
int getline_c(char s[], int lim);

void qsort(char lines[][MAXLEN], int left, int right);

int main(int argc, char *argv[])
{
	int nlines;

	if ((nlines = my_readlines(lines, MAXLINES)) >= 0) {
		qsort(lines, 0, nlines - 1);
		writelines(lines, nlines);
		return 0;
	} else {
		printf("error: input to big to sort\n");
		return 1;
	}
}

int my_readlines(char lines[][MAXLEN], int maxlines)
{
	int len, nlines;

	nlines = 0;
	while ((len = getline_c(lines[nlines], MAXLEN)) > 0) {
		if (nlines >= maxlines)
			return -1;
		else {
			lines[nlines++][len-1] = '\0';
		}
	}
}

void writelines(char lines[][MAXLEN], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lines++);
}

// Getline from section 1.9 in the C book.
int getline_c(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


void qsort(char v[][MAXLEN], int left, int right)
{
	int i, last;
	void swap(char v[][MAXLEN], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char v[][MAXLEN], int i, int j)
{
	char temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
