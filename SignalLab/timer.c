#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarmNum = 0;
time_t start;
time_t end;

void handler(int signum){
  alarmNum += 1;
  printf("Hello world!\n");
  alarm(1);
}

void handlerTwo(int signum){
  time_t runtime;
  end = time(NULL);
  runtime = end - start;

  printf("Number of alarms: %d", alarmNum);
  printf("\nRuntime: %d \n", (int)runtime);
  exit(0);
}

int main(int argc, char *argv[]){
  start = time(NULL);
  signal(SIGALRM, handler);
  signal(SIGINT, handlerTwo);
  alarm(1);

  while(alarm(1)){
    pause();
    printf("Turing was right!\n");
  }
  return 0;
}