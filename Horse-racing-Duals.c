#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define MAX_DIFF 10000000

int compare(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);

    int P[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &P[i]);

    qsort(P, N, sizeof(int), compare);

    int min_diff = MAX_DIFF;

    for (int i = 1; i < N; i++)
    {
        int diff = P[i] - P[i - 1];

        if (diff < min_diff)
            min_diff = diff;
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", min_diff);

    return 0;
}