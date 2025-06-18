#include "stdio.h"
#include "../include/input_processing.h"

int main(int argc, char **argv)
{
	int ch;
	struct processing_input input;
	init_processing_input(&input);

	printf("> ");

	while((ch = getchar()) != EOF) {
		process_char_from_input(&input, &ch);
		if(ch == '\n') {
			if(input.terminating_processing) {
				error_during_processing(&input);
			} else {
				execute_program(&input);
			}
			printf("> ");
			default_state_input(&input);
		}
	}
	printf("\n");
	default_state_input(&input);
	return 0;
}
