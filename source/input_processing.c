#include "../include/input_processing.h"

static void
shell_specific_separator_symbols(struct processing_input *input,
											 int* ch);

static int is_shell_specific_separator(int ch)
{
	if(ch == '&' || ch == '>' || ch == '<' || 
	   ch == '|' || ch == '(' || ch == ')' ||
	   ch == ';') {
		return 1;
	}
	return 0;
}

static void add_one_character_word(struct processing_input *input, int ch)
{
	string_add_char(&(input->tmp_word), ch);
	queue_of_str_add_str(&(input->words), &(input->tmp_word));
	string_clear(&(input->tmp_word));
}
static void add_word(struct processing_input *input)
{
	queue_of_str_add_str(&(input->words), &(input->tmp_word));
	string_clear(&(input->tmp_word));
}

static void clear_input(struct processing_input *input)
{
	input->double_quotes_number = 0;
	input->processing_mode = simple_mode;
	input->terminating_processing = no_error;
	input->exec_process_mode = exec_simple;
}

static void clear_resource(struct processing_input *input)
{
	queue_of_str_clear(&(input->words));
	string_clear(&(input->tmp_word));
}

static void change_mode_processing(struct processing_input *input)
{
	(input->double_quotes_number)++;
	if(input->processing_mode == simple_mode) {
		input->processing_mode = inside_quotes_mode;
	} else {
		input->processing_mode = simple_mode;
	}
}

static void end_input_expression(struct processing_input *input)
{
	int empty = 0;
	empty = string_is_empty(&(input->tmp_word));
	if((input->double_quotes_number)%2 != 0) {
		input->terminating_processing = unmatched_quotes_error;
		print_error(input);
		return;
	}
	if(empty) {
		return;
	}
	queue_of_str_add_str(&(input->words), &(input->tmp_word));
}

static void escape_character(struct processing_input *input)
{
	int ch;
	ch = getchar();
	switch(ch) {
		case '"':
		case '\\':
			string_add_char(&(input->tmp_word), ch);
			break;
		default:
			input->terminating_processing = escape_error;
			print_error(input);
	}
}

static void separator_symbols(struct processing_input *input, char ch)
{
	int empty = 0;
	empty = string_is_empty(&(input->tmp_word));
	if(input->processing_mode == simple_mode) {
		if(empty) {
			return;
		}
		add_word(input);
	} else {
		string_add_char(&(input->tmp_word), ch);
	}
}

static void double_quotes_character(struct processing_input *input, int *ch)
{
	int empty = 0;
	empty = string_is_empty(&(input->tmp_word));
	*ch = getchar();
	if(empty && *ch == '"') {
		*ch = getchar();
		if(*ch == '\n' || *ch == ' ' || *ch == '	') {
			add_word(input);
			return;
		}
		input->terminating_processing = incorrect_use_double_quotes;
		print_error(input);
	}
	change_mode_processing(input);
	if(*ch == ' ' || *ch == '	') {
		separator_symbols(input, *ch);
	} else if(*ch == '\n') {
		if(!empty) {
			queue_of_str_add_str(&(input->words), &(input->tmp_word));
		}
		return;
	} else {
		string_add_char(&(input->tmp_word), *ch);
	}
}

static void shell_specific_separator_symbols(struct processing_input *input,
											 int* ch)
{
	if(input->processing_mode != inside_quotes_mode) {
		if(!string_is_empty(&(input->tmp_word))) {
			add_word(input);
		}
		if(*ch != '&') {
			printf("Feature not implemented yet.\n");
			return;
		}
		input->exec_process_mode = exec_background;
		*ch = getchar();
		if(*ch != '\n') {
			input->terminating_processing = error_use_background_process;
			print_error(input);
		}
	} else {
		string_add_char(&(input->tmp_word), *ch);
	}
}

void init_processing_input(struct processing_input *input)
{
	input->double_quotes_number = 0;
	input->processing_mode = simple_mode;
	input->terminating_processing = no_error;
	input->exec_process_mode = exec_simple;
	string_init(&(input->tmp_word));
	queue_of_str_init(&(input->words));
}

void process_char_from_input(struct processing_input *input, int *ch)
{
	switch(*ch) {
		case 34:	/* " */
			double_quotes_character(input, ch);
			break;
		case 10:	/* \n */
			end_input_expression(input);
			break;
		case 32:	/* space */
		case 9:		/* TAB */
			separator_symbols(input, *ch);
			break;
		case 92:	/* \ */
			escape_character(input);
			break;
		case 38:	/* & */
		case 40:	/* ( */
		case 41:	/* ) */
		case 59:	/* ; */
		case 60:	/* < */
		case 62:	/* > */
		case 124:	/* | */
			shell_specific_separator_symbols(input, ch);
			break;
		default:
			string_add_char(&(input->tmp_word), *ch);
	}
}

void default_state_input(struct processing_input *input)
{
	clear_input(input);
	clear_resource(input);
}

void execute_program(struct processing_input *input)
{
	queue_of_str_print_content(&(input->words));
/*	process_command_and_execute(&(input->words));  */
}

void print_error(struct processing_input *input)
{
	switch(input->terminating_processing) {
		case escape_error:
			printf("Error: symbol \\ used for escaping: \" and \\.\n");
			break;
		case unmatched_quotes_error:
			printf("Error: unmatched quotes.\n");
			break;
		case incorrect_use_double_quotes:
			printf("Error: incorrect use double quotes.\n");
			break;
		case error_use_background_process:
			printf("Error: incorrect use backgroung process.\n");
			break;
		case no_error:
			break;
	}
}

void error_during_processing(struct processing_input *input)
{
	if(input->terminating_processing) {
		default_state_input(input);
	}
}
