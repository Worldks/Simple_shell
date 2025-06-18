#include "../include/string.h"

void string_init(struct string *tmp_word)
{
	init_dyn_arr(&(tmp_word->str));
	(tmp_word->str).arr[0] = '\0';
}

void string_clear(struct string *tmp_word)
{
	clear_dyn_arr(&(tmp_word->str));
}

void string_add_char(struct string *tmp_word, int ch)
{
	add_char_dyn_arr(&(tmp_word->str), ch);
}

int string_is_empty(struct string *tmp_word)
{
	int res = is_dyn_arr_empty(&(tmp_word->str));
	return res;
}

void string_delete(struct string *tmp_word)
{
	clear_dyn_arr(&(tmp_word->str));
	free((tmp_word->str).arr);
}
