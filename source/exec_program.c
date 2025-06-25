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
	} else {
		return NULL;
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

static void make_args(char ***args, struct queue_of_str *words)
{
	*args = args_from_command(words);
	if(!*args) {
/*		fprintf(stderr, "Empty command\n");	*/
		return;
	}
	fflush(stdin);
	fflush(stdout);
	fflush(stderr);
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

int exec_program_in_background(struct queue_of_str *words)
{
	int pid, wr, equal;
	char **args;
	make_args(&args, words);
	if(!args) {
		return -1;
	}
	equal = is_str_equal(args[0], "cd");
	if(equal) {
		change_current_working_dir_process(args);
		pid = getpid();
		return pid; 
	}
	pid = fork();
	if(pid == -1) {
		perror("fork()");
		exit(2);
	} else if(pid == 0) {
		execvp(args[0], args);
		perror("execvp(). can't execute program");
		fflush(stderr);
		_exit(1);
	}
	free(args);
	return pid;
}

int exec_program(struct queue_of_str *words)
{
	int pid, wr;
	int equal;
	char **args;
	make_args(&args, words);
	if(!args) {
		return -1;
	}
	equal = is_str_equal(args[0], "cd");
	if(equal) {
		change_current_working_dir_process(args);
		pid = getpid();
		return pid;
	}
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
		do {
			wr = wait(NULL);
		} while(wr != pid);
	}
	free(args);
	return pid;
}

void clear_zombies_nohang()
{
	int p;
	do {
		p = wait4(-1, NULL, WNOHANG, NULL);
	} while(p > 0);
}
