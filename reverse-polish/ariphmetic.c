#include <string.h>

#include "ariphmetic.h"

#define N 30

void grv_arph_add(char* a, char* b)
{
    const size_t l1 = strlen(a);
	const size_t l2 = strlen(b);
	int carry = 0;
	size_t i;

	for (i = 0; i < l1 || i < l2; i++)
	{
		/* школьный алгоритм сложения в столбик */
		const int d = (i < l1 ? a[i] - '0' : 0) + (i < l2 ? b[i] - '0' : 0) + carry;
		a[i] = d % 10 + '0';
		carry = d / 10;
	}

	/* на этот момент i указыват на конец первого числа */
	if (carry && i < N - 1)
		a[i++] = carry + '0';
	a[i] = '\0';	/* NOTE: нулевой символ, а не цифра ноль */
}

void grv_arph_substract(char* a, char* b) {}

void grv_arph_produt(char* a, char* b) {}

void grv_arph_negative(char* a) {}
