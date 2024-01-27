// 1. Write a simple C program to generate a random number 
// without initializing the seed for the random number 
// generator {Within a span of "one second", if you keep 
// running the program multiple times, you should see the same
// random number output}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef PRG1
int main() {
 // Seed the random number generator with the current time
// srand(time(NULL)); // Current time is taken as the seed; 
 // Generate a random number and print it
 int randomNumber = rand();
 printf("Random Number: %d\n", randomNumber);
 return 0;
}
#elif PRG2
int main() {
 // Get the current time
 time_t currentTime;
 time(&currentTime);
 // Convert the time to a string and display
 char* timeString = ctime(&currentTime);
 printf("Current Time: %s", timeString);
 return 0;
}
#endif