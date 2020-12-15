#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "colors.h"
#include "matrix.h"
#include "city.h"

int parser(FILE *f, char cities[LEN], int matrix[LEN][LEN])
{
    char city_first;
    char city_second;
    int cost, count = 0;
    int i, j;

    // Пропускам инфу.
    char str1[100];
    char str2[] = "--";
    while (!strstr(str1, str2))
        fscanf(f, "%s", str1);
    fseek(f, -4, SEEK_CUR);

    while (!feof(f))
    {

        fscanf(f, "    %c -- %c [label=\"%d\"];", &city_first, &city_second, &cost);

        if ((city_first == '}') || (city_second == '}'))
            break;
        // printf("%c %c %d\n", city_first, city_second, cost);
        i = find_city(cities, city_first, &count);
        j = find_city(cities, city_second, &count);
        // printf("%d %d %d\n", i, j, cost);
        matrix[i][j] = cost;
        matrix[j][i] = cost;
    }

    return count;
}
