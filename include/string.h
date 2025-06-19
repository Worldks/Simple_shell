#ifndef STRING_H_SENTRY
#define STRING_H_SENTRY
#include "dynamic_array.h"

enum { max_number_length = 12 };
enum compare { less, equal, greather };	/* equal - 1 => may use in if() */

struct string {
	struct dyn_arr str;
};

void string_init(struct string *tmp_word);
void string_clear(struct string *tmp_word);
void string_add_char(struct string *tmp_word, int ch);
void string_delete(struct string *tmp_word);
int string_is_empty(struct string *tmp_word);

int str_length(const char *str);
int is_str_equal(const char *str_1, const char *str_2);
void str_copy(char *dest, const char *src);
void number_to_str(int number, char *str);
enum compare compare_strings(const char *str_1, const char *str_2);
#endif
