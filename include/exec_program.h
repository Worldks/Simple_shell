#ifndef EXEC_PROGRAMS_H_SENTRY
#define EXEC_PROGRAMS_H_SENTRY
#define _DEFAULT_SOURCE
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "string.h"
#include "queue_of_strings.h"

int exec_program_in_background(struct queue_of_str *words);
int exec_program(struct queue_of_str *words);
void clear_zombies_nohang();

#endif
