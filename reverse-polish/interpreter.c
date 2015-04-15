#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "ariphmetic.h"
#include "stack.h"

#include "interpreter.h"

#define N 30

static void reverse_int(char* p)
{
	char t;
	const size_t len = strlen(p) + 1;
	size_t i;

	for (i = 1; i < len / 2; i++)
	{
		t = p[i];
		p[i] = p[len - i - 1];
		p[len - i - 1] = t;
	}
}

static int read_int(char* buf)
{
	int ch;
	size_t i;

	for (i = 1; i < N - 1; i++) {
		if((ch = getchar()) != EOF && isdigit(ch))
			buf[i] = ch;
		else
			break;
	}
	buf[0] = '+';
	buf[i] = '\0';
	ungetc(ch, stdin);
	reverse_int(buf);
	return !isdigit(ch) ? i : 0;
}

int grv_errno;

int grv_reverse_polish_interpreter(char* result)
{
	char op1[N], op2[N];
	int ch, pos = 0;
	char* const op = op1;

	while ((ch = getchar()) != EOF && ch != '\n')
	{
		if (isdigit(ch))
		{
			int len_int;
			ungetc(ch, stdin);
			if (!(len_int = read_int(op1)))
			{
				grv_errno = GRV_ERR_MEM;
				return pos;
			}
			grv_stack_push(op1);
			pos += len_int - 1;
		}
		else if ((ch == '+' || ch == '-' || ch == '*') && grv_stack_size() >= 2)
		{
			grv_stack_pop(op2);
			grv_stack_pop(op1);

			switch (ch)
			{
				case '+':
				grv_arph_add(op1, op2);
				break;

				case '-':
				grv_arph_substract(op1, op2);
				break;

				case '*':
				grv_arph_produt(op1, op2);
				break;
			}

			grv_stack_push(op1);
		}
		else if (ch == '-' && grv_stack_size() == 1)
		{
			/* унарный минус */
			grv_stack_pop(op1);
			grv_arph_negative(op1);
			grv_stack_push(op1);
		}
		else if (!isspace(ch))
		{
			/* TODO: разделить ошибку на два вида */
			grv_errno = GRV_ERR_SYMBOLS;
			return pos;
		}
		pos++;
	}

	if (grv_stack_size() != 1)
	{
		grv_errno = GRV_ERR_OPERATORS;
		return pos;
	}
	grv_stack_pop(result);
	reverse_int(result);

	grv_errno = 0;
	return -1;
}
