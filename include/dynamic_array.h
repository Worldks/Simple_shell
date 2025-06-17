#ifndef DYNAMIC_ARRAY_H_SENTRY
#define DYNAMIC_ARRAY_H_SENTRY
#include "stdlib.h"

enum { max_size_for_dyn_arr = 4 };

struct dyn_arr {
	char *arr;
	int max_size;
	int size_arr; /* place where should write character */
};

void init_dyn_arr(struct dyn_arr *tmp_word);
void clear_dyn_arr(struct dyn_arr *tmp_word);
void add_char_dyn_arr(struct dyn_arr *tmp_word, int ch);
int is_dyn_arr_empty(struct dyn_arr *tmp_word);
#endif
