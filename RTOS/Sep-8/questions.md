# Lab-5:
Additional Questions on fork(), exec(), wait() system calls
Date: 8th September 2018
1. WAP which forks a new process. Both the parent as well as the child
processes should display their process ids to the screen. {use getpid(),
getppid() system calls}
2. WAP which forks a new process. Let the child process initiate a counter to
zero and keep incrementing it until it reaches 999. Let it exit with a
value 255. 
Let the parent use the waitpid() system for the child to complete. And once the 
child completes the parent displays a message namely “Parent: Child 
processcompleted". Also let the parent output the exit value (exit status) of the 
child. 
What happens if there is no waitpid() in the parent? Observe.
3. (i) Create a child process from a program. Let the child process first sleep for
8 seconds and then output a message namely “I am the child”. Parent outputs a
message namely ‘I am the parent’ and then waits for the child to complete.
Execute the program and observe the result. 
What happens if there is no wait in the parent? Observe.
4. Create a child process which outputs your name to the screen and exits with a
value 255. Use wait() system call in the parent, for the child to complete 
execution. Also use
the WEXITSTATUS macro to display the status value returned by the child.
5. Spawn (create) a child process which executes ls command
6. Spawn a child process which executes ls command with option –l
7. Spawn a child which executes copy command cp (Note: the copy command
takes 2 arguments meant for source filename and destination file name.)
8. Fork 3 children . One of them executes ls, another date and the third pwd
command. Run the program and observe the results on each run.
9. Write a program which forks a new process. Let the child process compute the
summation of first n natural numbers, and let it output the result. Pass ‘n’ as a
commandline argument. The parent waits for the child to complete and finally
the parent process too outputs the result.
**