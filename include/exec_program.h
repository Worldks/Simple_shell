#ifndef EXEC_PROGRAMS_H_SENTRY
#define EXEC_PROGRAMS_H_SENTRY
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "string.h"
#include "queue_of_strings.h"

void process_command_and_execute(struct queue_of_str *words);

#endif
