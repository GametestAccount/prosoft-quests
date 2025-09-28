#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define to_rad(deg) ((deg * M_PI) / 180)

struct defib_info
{
    char name[64];
    double longitude;
    double latitude;
};

double get_dist(double longitudeA, double latitudeA, double longitudeB, double latitudeB)
{
    longitudeA = to_rad(longitudeA);
    latitudeA = to_rad(latitudeA);
    longitudeB = to_rad(longitudeB);
    latitudeB = to_rad(latitudeB);

    double x = (longitudeB - longitudeA) * cos((latitudeA + latitudeB) / 2);
    double y = latitudeB - latitudeA;

    return sqrt(pow(x, 2) + pow(y, 2)) * 6371;
}

double get_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            str[i] = '.';
            break;
        }
    }

    return atof(str);
}

int main()
{
    char LON[51] = "";
    scanf("%50s", LON);

    char LAT[51] = "";
    scanf("%50s", LAT);
    
    int N;
    scanf("%d", &N); fgetc(stdin);

    struct defib_info defibs[N];

    for (int i = 0; i < N; i++)
    {
        char DEFIB[257] = "";
        scanf("%[^\n]", DEFIB); fgetc(stdin);

        char *str = &DEFIB[0];
        char *sep;
        int sep_nom = 1;

        while ((sep = strsep(&str, ";")) != NULL)
        {
            switch (sep_nom)
            {
                case 2:
                    strncpy(defibs[i].name, sep, 63); break;
                case 5:
                    defibs[i].longitude = get_num(sep); break;
                case 6:
                    defibs[i].latitude = get_num(sep); break;
            }

            sep_nom++;
        }
    }

    double user_longitude = get_num(LON);
    double user_latitude = get_num(LAT);

    int min_dist_index = 0;
    double min_dist = get_dist(user_longitude, user_latitude, defibs[0].longitude, defibs[0].latitude);

    for (int i = 1; i < N; i++)
    {
        double dist = get_dist(user_longitude, user_latitude, defibs[i].longitude, defibs[i].latitude);

        if (dist < min_dist)
        {
            min_dist = dist;
            min_dist_index = i;
        }
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%s\n", defibs[min_dist_index].name);

    return 0;
}