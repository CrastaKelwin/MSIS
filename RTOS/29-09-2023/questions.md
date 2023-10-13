1. Write a program which creates a thread. The main thread should
publish its pid. Let the thread publish its thread id. Next the
thread computes the sum of first twenty five numbers and outputs the
result to the screen. {Use pthread_join() in the main, so that it
waits for the thread to finish its execution.}
Modify the above code such that the upper limit of the summation is
read from the user and is passed as a parameter to the thread.
2. Write a program which creates 3 threads.
case (i) Let the main thread input the value of n from the user.
{Hint:- You can store n in a global variable so that it is available
to all threads of the process} Each thread reads a message from the
user and displays the message n times.
case (ii) Modify your program such that the value of n is given by
the user and is passed as a parameter to the threads.
3. Write a program which creates two threads. Let the main thread
display a message, "Hello, main thread here!". Also the main thread
reads 2 integers n1 and n2 (which can range between 1 to 9) from the
user. Main should pass n1 to thread1, and n2 to thread2. Thread1 then
displays "Hello, thread1 here!" n1 times. Thread2 displays
"Hello,thread2 here!" n2 times.
4. Write a program which defines a global integer array. Let the main
read the length of the array and populate it. Next it creates 2
threads. Let the main pass the array length to the 2 threads. One
thread computes the sum of array elements and outputs the result. The
second thread publishes all odd numbers present in the array. {Use
pthread_join() in the main, so that it waits for the threads to
finish their execution.}
Suppose the array is defined in main, and the main has to pass both
the array as well as the array length to the threads, how will your
program change?
5. Define a global integer matrix of size 3 * 4. Let the main thread
populate the matrix with integers from the user. Create 4 threads.
Each thread computes the column sum of a particular column. The main
waits for the threads to complete their execution. Finally the main
computes the total sum of integers from the partial results given out
by the threads, and outputs the sum to the screen.
How will your program change if there are 3 threads, each computing
the sum of a particulr row, and finally the main thread computes the
total sum?

## Note: for compilation use pthread flag
```
gcc -pthread -o main.o *.c
```
***