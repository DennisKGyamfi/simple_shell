#include "shell.h"

/**
*e_puts - prints input string
* @str: string to be printed
*
* Return: Nothing
*/

void e_puts(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
eput_char(str[i]);
i++;
}
}

/**
* eput_char - writes the char c to stderr
* @c: The character to print
*
* Return: 1 (success).
* On error, -1 is returned, and errno is set appropriately.
*/

int eput_char(char c)
{
static int i;
static char buf[WRITE_BUFF_SIZE];

if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUFF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* put_fd - writes the character c to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int put_fd(char c, int fd)
{
static int i;
static char buf[WRITE_BUFF_SIZE];

if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUFF_FLUSH)
buf[i++] = c;
return (1);
}

/**
*puts_fd - prints an input string
* @str: the string to be printed
* @fd: the filedescriptor to write to
*
* Return: the number of chars put
*/

int puts_fd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += put_fd(*str++, fd);
}
return (i);
}
