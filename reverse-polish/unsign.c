#include <stddef.h>
#include <string.h>

#include "unsign.h"

#define N 30

void grv_unsgn_add(char* a, char* b)
{
    const size_t l1 = strlen(a);
	const size_t l2 = strlen(b);
	int carry = 0;
	size_t i;

	for (i = 1; i < l1 || i < l2; ++i)
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

void grv_unsgn_substract(char* a, char* b)
{
    const size_t l1 = strlen(a);
	const size_t l2 = strlen(b);
	int below = 0;
	size_t i;

	for (i = 1; i < l1 || i < l2; ++i)
	{
		/* копипаста из выше */
		int d = (i < l1 ? a[i] - '0' : 0) - (i < l2 ? b[i] - '0' : 0) - below;
		if (below = d < 0)
			d += 10;
		a[i] = d % 10 + '0';
	}

	/* на этот момент i указыват на конец первого числа */
	if (below);
	/* TODO: сигнализирование об ошибке */
}
