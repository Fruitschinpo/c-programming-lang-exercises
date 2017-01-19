#include <stdio.h>

#define LIM 1000

/*
 for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
         line[i] = c;
 Write a loop equivalent to the for loop above without using && or ||. 
*/

int main() 
{
        int i, c;
        char line[LIM];

        for (i = 0; (i < LIM - 1) * ((c=getchar()) != '\n') * (c !=EOF); ++i) 
                line[i] = c;
        printf("%s\n", line);
        return 0;
}
