#include "../include/queue_of_strings.h"

static char *make_new_word(struct string *tmp_word)
{
	int i = 0;
	char *tmp;
	if((tmp_word->str).size_arr == 0) {  /* empty word */
		(tmp_word->str).size_arr = 1;
		tmp = malloc(sizeof(char));
		*tmp = '\0';
		return tmp;
	}
	tmp = malloc(((tmp_word->str).size_arr + 1)*sizeof(char));
	for( ; i <= (tmp_word->str).size_arr; i++) {
		*(tmp+i) = ((tmp_word->str).arr)[i];
	}
	return tmp;
}

void queue_of_str_init(struct queue_of_str *words)
{
	words->first = NULL;
	words->last = NULL;
}

void queue_of_str_clear(struct queue_of_str *words)
{
	struct word_item *tmp;
	while(words->first != NULL) {
		tmp = words->first->next;
		free(words->first->word);
		free(words->first);
		words->first = tmp;
	}
	words->last = NULL;
}

void queue_of_str_print_content(struct queue_of_str *words)
{
	struct word_item *tmp;
	tmp = words->first;
	while(tmp != NULL) {
		printf("[%s]\n", tmp->word);
		tmp = tmp->next;
	}
}

void queue_of_str_add_str(struct queue_of_str *words, struct string *tmp_word)
{
	/* adding to END of list */
	struct word_item *tmp;
	tmp = malloc(sizeof(struct word_item));
	tmp->next = NULL;
	tmp->word = make_new_word(tmp_word);
	if(words->last) {
		words->last->next = tmp;
		words->last = tmp;
	} else {
		words->first = words->last = tmp;
	}
}
