#include <stdio.h>

#include "ant_algorithm.h"
#include "brute_force.h"
#include "matrix.h"
#include "array.h"
#include "ant.h"

#include "colors.h"

int calculate_Q(int matrix[LEN][LEN], int count)
{
	int Q = 0;

	for (int i = 0; i < count; i++)
		for (int j = 0; j < i; j++)
			Q += matrix[i][j];

	return Q * 2;
}

void evaporation(float matrix_pheromones[LEN][LEN], int count, float p)
{
	float tmp = 1 - p;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < i; j++)
		{
			matrix_pheromones[i][j] = tmp * matrix_pheromones[i][j]; 
			matrix_pheromones[j][i] = tmp * matrix_pheromones[j][i];
		}
}

array ant_algorithm(int matrix[LEN][LEN], int count, array cities, int tmax, float p, float alpha, float beta)
{
	printf("tmax = %d, p = %f alpha = %f, beta = %f\n", tmax, p, alpha, beta);

	int Q = calculate_Q(matrix, count);
	printf("Q = %d\n", Q);

	array best_way = copy_arr(cities);
	add_elem(&best_way, get_elem(best_way, 0));
	print_array(best_way, "Начальное best_way");

	int best_cost = get_path_cost(best_way, matrix);
	int curr_cost = 0;
	printf("best_cost = %d\n", best_cost);

	float matrix_pheromones[LEN][LEN];
	fill_matrix(matrix_pheromones, count, PHEROMONE_MIN);

	ant ants[ANTS_MAX_COUNT];

	generate_ants_array(ants, count);
	print_ants(ants, count);

	// ants_choose_way(ants, matrix_pheromones, matrix, count, alpha, beta);

	// print_ants(ants, count);

	// Цикл по дням.
	for (int t = 0; t < tmax; t++)
	{
		// Муравьев столько же, сколько и городов.
		// Поэтому кол-во == count.
		generate_ants_array(ants, count);

		// print_ants(ants, count);

		// Цикл по городам.
		// Один город не учитываем,
		// потому что мы с него начали.
		for (int i = 0; i < count - 1; i++)
		{
			// print_ants(ants, count);

			// Муравьи выбирают путь.
			ants_choose_way(ants, matrix_pheromones, matrix, count, alpha, beta);
		}

		// Добавляем последний город.
		// (Муравей должен вернуться в начальный город).
		for (int i = 0; i < count; i++)
			add_elem(&ants[i].way, get_elem(ants[i].way, 0));

		// print_ants(ants, count);

		// Ищем минимальный путь.
		for (int i = 0; i < count; i++)
		{
			curr_cost = get_path_cost(ants[i].way, matrix);
			if (curr_cost < best_cost)
			{
				best_cost = curr_cost;
				best_way = copy_arr(ants[i].way);

				red();
				printf("curr_cost = %d best_cost = %d\n", curr_cost, best_cost);
				print_array(best_way, "best_way");
			}
		}
	}
}