#ifndef STRINGS_QUEUE_H_SENTRY
#define STRINGS_QUEUE_H_SENTRY
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

struct word_item {
	char *word;
	struct word_item *next;
};

struct queue_of_str {
	struct word_item *first, *last;
};

void queue_of_str_init(struct queue_of_str *words);
void queue_of_str_clear(struct queue_of_str *words);
void queue_of_str_print_content(struct queue_of_str *words);
void queue_of_str_add_str(struct queue_of_str *words, struct string *tmp_word);

#endif
