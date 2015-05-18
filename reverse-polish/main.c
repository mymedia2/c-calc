#include <stdio.h>
#include <string.h>
#include "interpreter.h"

#define N 30

int main(int argc, char* argv[])
{
	int pos;
	char result[N];
	if (!(argc == 2 && !strcmp(argv[1], "-n")))
		printf("> ");
	pos = grv_reverse_polish_interpreter(result);
	if (pos == -1)
		printf("%s\n", result + (result[0] == '+' ? 1 : 0));
	else
	{
		int i;
		char* err_str;
		switch (grv_errno)
		{
			case GRV_ERR_MEM:
			err_str = "слишком длинное число";
			break;
			case GRV_ERR_SYMBOLS:
			err_str = "неизвестный символ";
			break;
			case GRV_ERR_OPERATORS:
			err_str = "недостаточно операторов";
			break;
			default:
			err_str = "неизвестная ошибка";
		}
		for (i = 0; i < pos + 2; i++)
			fprintf(stderr, " ");
		fprintf(stderr, "^\n");
		fprintf(stderr, "ошибка:1:%d: %s\n", pos + 1, err_str);
	}
	return 0;
}
