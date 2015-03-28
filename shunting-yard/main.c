#include <stdio.h>
#include <string.h>
#include "shunting-yard.h"

#define N 1000

int main(int argc, char* argv[])
{
	if (!(argc == 2 && !strcmp(argv[1], "-n")))
		printf("> ");
	grv_shunting_yard();
	printf("\n");
	return 0;
}
