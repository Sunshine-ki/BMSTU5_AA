#ifndef _ANT_

#define _ANT_

#include "define.h"
#include "array.h"

typedef struct
{
	// Пройденный муравьем путь.
	// Т.е. список вершин, которые
	// муравей уже посетил.
	array way;
	// Маршрут.
	// Т.е. список вершин, которые
	// Муравей должен посетить.
	array route;
	// int cost;
} ant;

#endif