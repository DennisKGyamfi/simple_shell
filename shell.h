#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* hsh.c */
int hsh(info_t *, char **);
int search_builtin(info_t *);
void search_cmd(info_t *);
void fork_cmd(info_t *);

/* path.c */
int if_cmd(info_t *, char *);
char *dup_char(char *, int, int);
char *search_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* error_string_func.c */
void e_puts(char *);
int eput_char(char);
int put_fd(char c, int fd);
int puts_fd(char *str, int fd);

/* string_functions.c */
int str_len(char *);
int str_cmp(char *, char *);
char *start_with(const char *, const char *);
char *str_cat(char *, char *);

/* string_functions2.c */
char *str_cpy(char *, char *);
char *str_dup(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_chr(char *, char);

/* string_functions4.c */
char **str_tow(char *, char *);
char **str_tow2(char *, char);

/* memory_functions */
char *mem_set(char *, char, unsigned int);
void f_free(char **);
void *re_alloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int b_free(void **);

/* more_functions.c */
int interactive(info_t *);
int if_delim(char, char *);
int is_alpha(int);
int _atoi(char *);

/* more_functions2.c */
int err_atoi(char *);
void print_err(info_t *, char *);
int prints_d(int, int);
char *convert_numb(long int, int, int);
void rem_comments(char *);

/* builtin_emulators.c */
int my_exit(info_t *);
int my_cd(info_t *);
int my_help(info_t *);

/* builtin_emulators2.c */
int my_history(info_t *);
int my_alias(info_t *);

/* getline.c module */
ssize_t gets_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigint_Handler(int);

/* info.c module */
void clear_information(info_t *);
void set_information(info_t *, char **);
void free_information(info_t *, int);

/* env.c module */
char *get_envir(info_t *, const char *);
int my_envir(info_t *);
int my_setenvir(info_t *);
int my_unsetenvir(info_t *);
int populate_envir_list(info_t *);

/* env2.c module */
char **get_environment(info_t *);
int unset_env(info_t *, char *);
int set_env(info_t *, char *, char *);

/* file_handle_func.c */
char *get_historyfile(info_t *info);
int writes_history(info_t *info);
int reads_history(info_t *info);
int construct_history_list(info_t *info, char *buf, int linecount);
int re_number_history(info_t *info);

/* liststr.c module */
list_t *sum_node(list_t **, const char *, int);
list_t *sum_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int del_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* liststr2.c module */
size_t list_leng(const list_t *);
char **list_to_str(list_t *);
size_t prints_list(const list_t *);
list_t *node_begins_with(list_t *, char *, char);
ssize_t gets_node_index(list_t *, list_t *);

/* chain.c */
int if_chain(info_t *, char *, size_t *);
void checks_chain(info_t *, char *, size_t *, size_t, size_t);
int change_alias(info_t *);
int change_vars(info_t *);
int change_string(char **, char *);

#endif
