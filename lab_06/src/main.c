// sfdp -Tpng graph.gv -o graph.png
// Результат png-шник (путь: color=red, penwidth=3.0)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#include "define.h"
#include "colors.h"

#include "brute_force.h"
#include "matrix.h"
#include "parser.h"
#include "city.h"
#include "array.h"

int main(int argc, char * argv[])
{
    array cities; // Города представленые индексами.

    char city_names[LEN]; // Города представленые буквами.
    int matrix[LEN][LEN]; // матрица смежности

    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        printf("Ошибка при попытки открыть файл.\n");
        return ERROR_OPEN_FILE;
    }

    int count = parser(f, city_names, matrix);

    fclose(f);

    create_cities_array(&cities, count);

    print_cities(cities, city_names);
    print_matrix(matrix, count);

    array result = get_shortest_path(cities, matrix);

    print_cities(result, city_names);

    parser_in_gv(RESULT_FILE_NAME, city_names, matrix, result, count);

    system(CREATE_RESULT_FILE);
    system(OPEN_RESULT_FILE);

    return OK;
}
