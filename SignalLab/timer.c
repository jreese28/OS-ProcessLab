#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int);
void handler2(int);
int alarmTrigger = 0;
int alarmNum = 0;

time_t start, stop;

void handler(int signum){
    alarmTrigger = 1;
    printf("Hello World!\n");
    alarmNum++;
    sleep(2);

//exit after printing
}

void handler2(int signum){
    int totalTime;
    stop = time(NULL);
    totalTime = stop - start;
    printf("Number of alarms: %d \n", alarmNum);
    printf("Total time: %d \n", totalTime, " seconds.");
}

int maint(int argc, char * argv[]){
    start = time(NULL);
    
    signal(SIGALRM, handler);
    signal(SIGINT, handler2);

    //register handler to SIGALRM

    while(1){
        alarmTrigger = 0;
        alarm(2);
        while(alarmTrigger == 0){
            printf("Turning was right!\n");
        }
        return 0;
    }
}