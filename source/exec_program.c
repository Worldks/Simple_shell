#include "../include/exec_program.h"

static char **args_from_command(struct queue_of_str *list)
{
	struct word_item *tmp;
	int wcnt, i, equal;
	char **args;
	tmp = list->first;
	for(wcnt = 0; tmp; tmp = tmp->next) {
		wcnt++;
	}
	if(wcnt) {
		args = malloc((wcnt+1)*sizeof(char*));
	}
	tmp = list->first;
	for(i = 0; i < wcnt; i++) {
		args[i] = tmp->word;
		tmp = tmp->next;
	}
	args[i] = NULL;
	equal = is_str_equal(args[0], "cd");
	if(equal) {
		if(wcnt > 2) {
			return NULL;
		}	
	}
	return args;
}

static int exec_program(char* const *args)
{
	int pid, wr, status;
	pid = fork();
	if(pid == -1) {
		perror("fork()");
		exit(2);
	} else if(pid == 0) {
		execvp(args[0], args);
		perror("execvp(). can't execute program");
		fflush(stderr);
		_exit(1);
	} else {
		wr = wait(&status);
	}
	return pid;
}

static void change_current_working_dir_process(char* const *args)
{
	int res;
	char *home_dir;
	if(args[1]) {
		res = chdir(args[1]);
	} else {
		home_dir = getenv("HOME");
		if(home_dir) {
			res = chdir(home_dir);
		} else {
			fprintf(stderr, "I don't know your home directory.\n");
			return;
		}
	}
	if(res == -1) {
		perror(args[1]);
	}
}

void process_command_and_execute(struct queue_of_str *words)
{
	int equal;
	char **args;
	args = args_from_command(words);
	if(!args) {
		fprintf(stderr, "Uncorrect command\n");
		return;
	}
	fflush(stdin);
	fflush(stdout);
	fflush(stderr);
	equal = is_str_equal(args[0], "cd");
	if(equal) {
		change_current_working_dir_process(args);
	} else {
		exec_program(args);
	}
	free(args);
}
