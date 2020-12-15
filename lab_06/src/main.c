// sfdp -Tpng graph.gv -o graph.png
// TODO: Как результат можно сделать png-шник, показав вот так путь: color=red, penwidth=3.0.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "define.h"
#include "colors.h"
#include "matrix.h"
#include "parser.h"
#include "city.h"

int main()
{
    char array_cities[LEN]; // Города представлены буквами.
    int matrix[LEN][LEN];   // матрица смежности

    char cities[LEN];

    FILE *f = fopen(FILE_NAME, "r");

    int count = parser(f, cities, matrix);

    print_cities(cities, count);
    print_matrix(matrix, count);

    fclose(f);

    return OK;
}
