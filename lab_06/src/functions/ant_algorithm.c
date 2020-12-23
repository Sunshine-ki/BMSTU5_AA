#include <stdio.h>

#include "ant_algorithm.h"
#include "brute_force.h"
#include "matrix.h"
#include "array.h"
#include "ant.h"

int calculate_Q(int matrix[LEN][LEN], int count)
{
	int Q = 0;

	for (int i = 0; i < count; i++)
		for (int j = 0; j < i; j++)
			Q += matrix[i][j];

	return Q * 2;
}

array ant_algorithm(int matrix[LEN][LEN], int count, array cities, int tmax, float p, float alpha, float beta)
{
	printf("tmax = %d, p = %f alpha = %f, beta = %f\n",  tmax, p, alpha, beta);

	int Q = calculate_Q(matrix, count);
	printf("Q = %d\n", Q);
	
	array best_way = copy_arr(cities);
	add_elem(&best_way, get_elem(best_way, 0));
	print_array(best_way, "Начальное best_way");

	int best_cost = get_path_cost(best_way, matrix);
	printf("best_cost = %d\n", best_cost);

	float matrix_pheromones[LEN][LEN];
	fill_matrix(matrix_pheromones, count, PHEROMONE_MIN);

	ant ants[ANTS_MAX_COUNT];
	
	generate_ants_array(ants, count);
	print_ants(ants, count);

	// next_city(ants, matrix_pheromones, matrix, count, alpha, beta);
	
	// print_ants(ants, count);


	// Цикл по дням.
	for (int t = 0; t < tmax; t++)
	{
		// Муравьев столько же, сколько и городов.
		// Поэтому кол-во == count.
		generate_ants_array(ants, count);
		print_ants(ants, count);
		
		// Цикл по муравьям.
		for (int i = 0; i < count; i++)
		{
			// Цикл по городам.
			// Один город не учитываем, 
			// потому что мы с него начали.
			for (int j = 0; j < count - 1 ; j++)
			{
				// Муравьи выбирают следующий день. 
				next_city(ants, matrix_pheromones, matrix, count, alpha, beta);
			}
		}

	}

}