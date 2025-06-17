#ifndef STRINGS_QUEUE_H_SENTRY
#define STRINGS_QUEUE_H_SENTRY
#include "dynamic_array.h"
#include "stdio.h"
#include "stdlib.h"

struct word_item {
	char *word;
	struct word_item *next;
};

struct str_queue {
	struct word_item *first, *last;
};

void init_str_queue(struct str_queue *words);
void clear_str_queue(struct str_queue *words);
void print_str_queue_content(struct str_queue *words);
void add_str_to_queue(struct str_queue *words, struct dyn_arr *tmp_word);

#endif
