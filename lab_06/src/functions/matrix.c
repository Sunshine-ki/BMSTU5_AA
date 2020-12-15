#include <stdio.h>

#include "matrix.h"

void print_matrix(int matrix[LEN][LEN], int const count)
{
	// printf("count: %d\n  ", count);

	for (int i = 0; i < count; i++)
		printf("%d\t", i);
	puts("");

	for (int i = 0; i < count; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < count; j++)
			printf("%d\t", matrix[i][j]);
		puts("");
	}
	puts("");
}