#ifndef INPUT_PROCESSING_SENTRY
#define INPUT_PROCESSING_SENTRY
#include "string.h"
#include "queue_of_strings.h"
#include "exec_program.h"

enum input_mode  { simple_mode,         		inside_quotes_mode          };
enum input_error { no_error,            	    escape_error,  
				   unmatched_quotes_error,		incorrect_use_double_quotes,
				   error_use_background_process								};
enum background_process { exec_background, exec_simple };

struct processing_input {
	enum background_process exec_process_mode;
	enum input_error terminating_processing;
	enum input_mode processing_mode;
	int double_quotes_number;
	struct string tmp_word;
	struct queue_of_str words;
};

void init_processing_input(struct processing_input *input);
void process_char_from_input(struct processing_input *input, int *ch);
void execute_program(struct processing_input *input);
void error_during_processing(struct processing_input *input);
void default_state_input(struct processing_input *input);
void print_error(struct processing_input *input);
#endif
