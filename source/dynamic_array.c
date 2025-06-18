#include "../include/dynamic_array.h"

static void increase_dyn_arr_size(struct dyn_arr *arr)
{
	int i = 0;
	char *new_arr, *old_arr;
	if(arr->max_size == 0) {
		arr->max_size = 1;
	}
	new_arr = malloc(2*(arr->max_size)*sizeof(char));
	old_arr = arr->arr;
	for( ; i <= arr->size_arr; i++) {
		*(new_arr+i) = *(old_arr+i);
	}
	free(old_arr);
	arr->arr = new_arr;
	arr->max_size = 2*(arr->max_size);
}

void init_dyn_arr(struct dyn_arr *tmp_word)
{
	tmp_word->max_size = max_size_for_dyn_arr;
	tmp_word->size_arr = 0;
	tmp_word->arr = malloc(max_size_for_dyn_arr*sizeof(char));
}

void clear_dyn_arr(struct dyn_arr *tmp_word)
{
	tmp_word->size_arr = 0;
	(tmp_word->arr)[tmp_word->size_arr] = '\0'; /* for empty string */
}

void add_char_dyn_arr(struct dyn_arr *tmp_word, int ch)
{
	if(tmp_word->size_arr == tmp_word->max_size - 1)
		increase_dyn_arr_size(tmp_word);
	(tmp_word->arr)[tmp_word->size_arr] = ch;
	(tmp_word->size_arr)++;
	(tmp_word->arr)[tmp_word->size_arr] = '\0';
}

int is_dyn_arr_empty(struct dyn_arr *tmp_word)
{
	return (tmp_word->size_arr == 0) ? 1 : 0;
}
