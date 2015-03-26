#include <ctype.h>
#include <stdio.h>
#include "shunting-yard.h"
#include "stack.h"

int grv_shunting_yard()
{
	char ch, op;

	grv_stack_push('(');

	while ((ch = getchar()) != EOF && ch != '\n')
	{
		switch (ch)
		{
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			putchar(ch);
			continue;

			case '+': case '-': case '*':
			while ((op = grv_stack_pop()) != '(' && !(ch == '*' && op != '*'))
				putchar(op);
			// возвращаем скобку или операнд обратно
			grv_stack_push(op);
			// вставляем оператор
			grv_stack_push(ch);
			break;

			case '(':
			grv_stack_push(ch);
			break;

			case ')':
			while ((op = grv_stack_pop()) != '(')
				putchar(op);
			break;

			case ' ':
			putchar(' ');
			break;

			default:
			// TODO: доделать
			printf("err");
		}
		putchar(' ');
	}

	while ((op = grv_stack_pop()) != '(')
		putchar(op);
}
