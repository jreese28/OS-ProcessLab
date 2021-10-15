//J'nya Reese
//Dr. Burge
//Operating Systems Fall 2021
/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmTrigger = 0;
int alarmNum = 0;

time_t start, stop;

void handler(int signum)
{ //signal handler
alarmTrigger = 1;
  printf("Hello World!\n");
  exit(1); //exit after printing
}

int main(int argc, char * argv[])
{

  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1) {
    alarmTrigger = 0;
    alarm(2);
    while(alarmTrigger == 0){
      printf("Turning was right!\n");
    }
  }; //busy wait for signal to be delivered
  return 0; //never reached
}