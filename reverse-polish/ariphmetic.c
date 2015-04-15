#include "unsign.h"

#include "ariphmetic.h"

static int is_positive(char* a) {
	return a[0] == '+';
}

void grv_arph_add(char* a, char* b) {
	if (is_positive(a) == is_positive(b)) {
		grv_unsgn_add(a, b);
	} else if (is_positive(a)) {
		grv_unsgn_substract(a, b);
	} else {
		//fprintf(stderr, "%%s: ошибка: не реализовано");
		/* обменять местами a и b */
		//grv_unsgn_substract(b, a);
	}
}

void grv_arph_substract(char* a, char* b) { }

void grv_arph_produt(char* a, char* b) { }

void grv_arph_negative(char* a) { }
