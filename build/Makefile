CC = gcc
CFLAGS = -Wall -g -ansi -pedantic

string.o: ../source/string.c ../include/string.h
	$(CC) $(CFLAGS) -c $< -o $@
queue_of_str.o: ../source/queue_of_strings.c ../include/queue_of_strings.h
	$(CC) $(CFLAGS) -c $< -o $@
input_processing.o: ../source/input_processing.c ../include/input_processing.h
	$(CC) $(CFLAGS) -c $< -o $@
exec_program.o: ../source/exec_program.c ../include/exec_program.h
	$(CC) $(CFLAGS) -c $< -o $@
shell: ../source/main.c string.o queue_of_str.o input_processing.o exec_program.o
	$(CC) $(CFLAGS) $^ -o shell

remove:
	rm *.o shell
run: shell
	./shel
clear:
	rm *.o
