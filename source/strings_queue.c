#include "../include/strings_queue.h"

static char *make_new_word(struct dyn_arr *arr)
{
	int i = 0;
	char *tmp;
	if(arr->size_arr == 0) {  /* empty word */
		arr->size_arr = 1;
		tmp = malloc(sizeof(char));
		*tmp = '\0';
		return tmp;
	}
	tmp = malloc((arr->size_arr + 1)*sizeof(char));
	for( ; i <= arr->size_arr; i++)
		*(tmp+i) = (arr->arr)[i];
	return tmp;
}

void init_str_queue(struct str_queue *words)
{
	words->first = NULL;
	words->last = NULL;
}

void clear_str_queue(struct str_queue *words)
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

void print_str_queue_content(struct str_queue *words)
{
	struct word_item *tmp;
	tmp = words->first;
	while(tmp != NULL) {
		printf("[%s]\n", tmp->word);
		tmp = tmp->next;
	}
}

void add_str_to_queue(struct str_queue *words, struct dyn_arr *tmp_word)
{
	/* adding to END of list */
	struct word_item *tmp;
	tmp = malloc(sizeof(struct word_item));
	tmp->next = NULL;
	tmp->word = make_new_word(tmp_word);
	if(words->last) {
		words->last->next = tmp;
		words->last = tmp;
	} else
		words->first = words->last = tmp;
}
