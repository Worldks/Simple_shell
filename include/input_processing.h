#ifndef INPUT_PROCESSING_SENTRY
#define INPUT_PROCESSING_SENTRY
#include "dynamic_array.h"
#include "strings_queue.h"

enum input_mode  { simple_mode,             inside_quotes_mode          };
enum input_error { no_error,                escape_error,  
				   unmatched_quotes_error,  incorrect_use_double_quotes };

struct processing_input {
	enum input_error terminating_processing;
	int double_quotes_number;
	enum input_mode processing_mode;
	struct dyn_arr tmp_word;
	struct str_queue words;
};

void init_processing_input(struct processing_input *input);
void process_char_from_input(struct processing_input *input, int *ch);
void execute_program(struct processing_input *input);
void error_during_processing(struct processing_input *input);
void default_state_input(struct processing_input *input);
void print_error(struct processing_input *input);
#endif
