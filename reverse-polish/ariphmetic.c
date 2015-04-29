#include "unsign.h"

#include <string.h>
#include "ariphmetic.h"

static int is_positive(char* a) {
	return a[0] == '+';
}

// меняем местами строки
void swap(char* a, char* b) {
	int i;
	char temp;
	const size_t l1 = strlen(a);
	const size_t l2 = strlen(b);

	for (i = 1; i <= l1 || i <= l2; ++i) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

// сравниваем два числа, > 0 если а > b,
// 0, когда а = b и < 0, когда a < b 
int unsign_cmp(char* a, char* b) {
	int i;
	const size_t l1 = strlen(a);
	const size_t l2 = strlen(b);
	
	if( l1 != l2 ) return l1 > l2;
	for (i = l1; i != 0; --i) {
		if (a[i] != b[i]) return a[i] - b[i];
	}
	return l1 > l2;
}

void grv_arph_add(char* a, char* b) {
	if (is_positive(a) == is_positive(b)) {
		grv_unsgn_add(a, b);
	} else if (is_positive(a)) {
		if (unsign_cmp(a, b)) {
			a[0] = '+';
		} else {
			swap(a, b);
			a[0] = '-';
		}
		grv_unsgn_substract(a, b);
	} else {
		//fprintf(stderr, "%%s: ошибка: не реализовано");
		/* обменять местами a и b */
		swap(a, b);		
		if (unsign_cmp(a, b)) {
			a[0] = '+';
		} else {
			swap(a, b);
			a[0] = '-';
		}
		grv_unsgn_substract(b, a);
	}
}

void grv_arph_substract(char* a, char* b) {
	grv_arph_negative(b);
	grv_arph_add(a, b);
}

void grv_arph_produt(char* a, char* b) { }

void grv_arph_negative(char* a) { 
	a[0] = (a[0] == '+') ? '-' : '+';
}
