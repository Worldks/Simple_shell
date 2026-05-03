# Overview  
The program will only compile under Unix (uses Posix API).  

Программа скомпилируется только под Unix(использует Posix API).  

#  Build  
В директории build  
>make shell  

# Usage  
Parse a string from standard input and execute an external program with the specified command-line parameters, waiting for it to complete.

Split a string into words. Word separators are spaces and tabs. Within quotation marks, both spaces and tabs are treated as simple characters that do not separate words.
The command interpreter should terminate only in one case: if an "end of file" condition occurs in the standard input stream.
Before entering the next line, a prompt is displayed, using the ">" character.
Words can include the " and \ characters, escaping them with the "\" character.

An empty word can be formed by two consecutive "" characters outside of words, i.e., when the accumulated word is empty and the closing quotation mark is immediately followed by either a space character or the end of a line.

Entering the cd command changes the process's current directory.

If cd is specified without a parameter, the command interpreter will set the current directory to the user's home directory.

It is possible to run commands in the background using the & separator character. To run a command in the background, the & character must be at the end of the line. If anything other than spaces follows it, an error will be returned.  

Анализ строки со стандартного ввода и выполнение внешний программы с заданными параметрами командной строки и ожидания ее завершения.  
Разбиение строки на слова. Разделители слов: пробел и табуляция. Внутри кавычек и пробел, и табуляция воспринимаются как простые символы, не отделяющие слова друг от друга.  
Командный интрепретатор должен завершать работу только в одном случае: если в потоке стандартного ввода возникла ситуация "конец файла".  
Перед вводом очередной строки выдается приглашение к вводу,  символ ">".  
В слова можно включать сивол " и \, экранируя их символом  "\".  
Можно сформировать пустое слово, это два симола "", встреченные подряд вне слов, т.е. когда накопленное слово пусто, а сразу после закрывающей кавычки идет либо пробельный символ, либо конец строки.  
При вводе команды cd происходит смена текущей директории процесса.  
Если cd задана без параметра, то командный интерпретатор установит в качестве текущей домашнюю директорию пользователя.  
Есть возможность запуска команд в фоновом режиме с помощью симолва-разделителя &. Для запуска команды в фоново режиме символ & должен располагаться в конце строки, т.е. если после него есть ещё что-то, кроме пробелов, будет выдана ошибка.  
