#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEMP 5526

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
**/

int main()
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);

    int min_temp = MAX_TEMP;

    for (int i = 0; i < n; i++)
    {

        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);

        if (abs(t) < abs(min_temp))
            min_temp = t;

        if (abs(t) == abs(min_temp))
        {
            if (t > 0)
            min_temp = t;
        }
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    if (n == 0)
        printf("0\n");
    else
        printf("%d\n", min_temp);

    return 0;
}