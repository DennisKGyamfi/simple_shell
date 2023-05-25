Project: 0x16. C - Simple Shell

*List of allowed functions and system calls*
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)


*Tasks*

0. *Betty would be proud*
Write a beautiful code that passes the Betty checks


1. *Simple shell 0.1*
Write a UNIX command line interpreter.

* Usage: simple_shell
Your Shell should:

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

* use the PATH
* implement built-ins
* handle special characters : ", ', `, \, *, &, #
* be able to move the cursor
* handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…


2. *Simple shell 0.2*

Simple shell 0.1 +

* Handle command lines with arguments


3. *Simple shell 0.3*

Simple shell 0.2 +

* Handle the PATH
* fork must not be called if the command doesn’t exist


4. *Simple shell 0.4*

Simple shell 0.3 +

* Implement the exit built-in, that exits the shell
* Usage: exit
* You don’t have to handle any argument to the built-in exit


5. *Simple shell 1.0*

Simple shell 0.4 +

* Implement the env built-in, that prints the current environment

