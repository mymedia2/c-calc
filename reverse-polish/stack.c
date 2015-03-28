#include <stddef.h>
#include <string.h>

#include "stack.h"

#define N 30

static char container[1000][N];
static size_t count = 0;

void grv_stack_push(char* p)
{
	strcpy(container[count++], p);
}

void grv_stack_pop(char* p)
{
	strcpy(p, container[--count]);
}

size_t grv_stack_size()
{
	return count;
}
