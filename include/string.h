#ifndef STRING_H_SENTRY
#define STRING_H_SENTRY
#include "dynamic_array.h"

struct string {
	struct dyn_arr str;
};

void string_init(struct string *tmp_word);
void string_clear(struct string *tmp_word);
void string_add_char(struct string *tmp_word, int ch);
void string_delete(struct string *tmp_word);
int string_is_empty(struct string *tmp_word);
#endif
