#include <stdio.h>

#include "city.h"

void print_cities(char cities[LEN], int const count)
{
	printf("count: %d\n", count);
	for (int i = 0; i < count; i++)
		printf("%d: %c\t", i, cities[i]);
	puts("");
}

int find_city(char cities[LEN], char city, int *count)
{
	int i = 0;
	while (i < *count)
	{
		if (city == cities[i])
			return i;
		i++;
	}
	cities[i] = city;
	(*count)++;
	return i;
}