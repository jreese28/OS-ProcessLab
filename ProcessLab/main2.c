#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid[MAX_COUNT];
     int i;

     for(i = 0 ; i < MAX_COUNT ; i++){
       pid[i] = fork();

       switch(pid[i]){
         case 0:
         ChildProcess();
         wait();
         break;

         case 1:
         break;

         default:
         ParentProcess();
         break;
       };
     };

}

void  ChildProcess(void)
{
  int   i;

  time_t t;
  srand((unsigned) time(&t));

  for(i = 1; i <= (rand() % 31) ; i++){
    printf("Child pid: %d is going to sleep.\n", getpid());
    sleep(rand() % 11);
    printf("Child pid: %d is awake.\n Where is my parent: %d\n", getpid(), getppid());
  }
  exit(0);
}

void  ParentProcess(void)
{
     int   i;
     int status;

     wait(&status);
     printf("Child pid: %d is done.\n", status);
}