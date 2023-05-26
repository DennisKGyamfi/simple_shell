#include "shell.h"

/**
* my_envir - prints the current environment
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/

int my_envir(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* get_envir - gets the value of an environ variable
* @info: Structure containing potential arguments. Used to maintain
* @name: environ var name
*
* Return: the value
*/

char *get_envir(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = start_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
* my_setenvir - Initialize a new environment variable,
*             or modify an existing one
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/

int my_setenvir(info_t *info)
{
if (info->argc != 3)
{
e_puts("Incorrect number of arguements\n");
return (1);
}
if (set_env(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* my_unsetenvir - Remove an environment variable
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/

int my_unsetenvir(info_t *info)
{
int i;

if (info->argc == 1)
{
e_puts("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
unset_env(info, info->argv[i]);

return (0);
}

/**
* populate_envir_list - populates env linked list
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/

int populate_envir_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
sum_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
