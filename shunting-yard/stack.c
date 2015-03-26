#include <stddef.h>
#include "stack.h"

#define N 1000

static char container[N];
static size_t count = 0;

void grv_stack_push(char ch)
{
	container[count++] = ch;
}

char grv_stack_pop()
{
	return container[--count];
}

size_t grv_stack_size()
{
	return count;
}
