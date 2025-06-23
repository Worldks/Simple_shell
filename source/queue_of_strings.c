#include "../include/queue_of_strings.h"

static char *copy_word(struct string *tmp_word)
{ /* make copy of string and add to queue */
	char *str;
	if(string_is_empty(tmp_word)) {
		str = malloc(sizeof(char));
		*str = '\0';
		return str;
	}
	str = malloc(tmp_word->occupied_size*sizeof(char));
	str_copy(str, tmp_word->str);
	return str;
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
	tmp->word = copy_word(tmp_word);
	if(words->last) {
		words->last->next = tmp;
		words->last = tmp;
	} else {
		words->first = words->last = tmp;
	}
}
