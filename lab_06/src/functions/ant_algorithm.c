#include <stdio.h>

#include "ant_algorithm.h"
#include "brute_force.h"
#include "matrix.h"
#include "array.h"


int calculate_Q(int matrix[LEN][LEN], int count)
{
	int Q = 0;

	for (int i = 0; i < count; i++)
		for (int j = 0; j < i; j++)
			Q += matrix[i][j];

	return Q * 2;
}

array ant_algorithm(int matrix[LEN][LEN], int count, array cities, int tmax, int p, int alpha, int beta)
{
	int Q = calculate_Q(matrix, count);
	printf("Q = %d\n", Q);
	
	array best_way = copy_arr(cities);
	add_elem(&best_way, get_elem(best_way, 0));
	print_array(best_way, "Начальное best_way");

	int best_cost = get_path_cost(best_way, matrix);
	printf("best_cost = %d\n", best_cost);

	float matrix_pheromones[LEN][LEN];
	fill_matrix(matrix_pheromones, count, PHEROMONE_MIN);


}