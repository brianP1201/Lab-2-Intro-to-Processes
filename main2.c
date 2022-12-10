#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;
     for(i=0; i<2; i++){
          pid = fork();
          if (pid == 0){
               ChildProcess(i);
          }
          else if (pid < 0){
               printf("Error in Fork\n");
          }
     }
     ParentProcess();
     
}

void  ChildProcess(int childId)
{
     int random_num, random_num2;
     int   i;

     srand(getpid());
     random_num = (rand()%30) +1;
     for(i=0; i < random_num; i++){
          printf("Child Pid: %d is going to sleep!\n", getpid());
          random_num2 = rand() % 10;
          sleep(random_num2 + 1);
          printf("Child Pid: is awake!\nWhere is My Parent %d ? \n", getppid());
     }

    //  for (i = 1; i <= MAX_COUNT; i++)
    //       printf("   This line is from child, value = %d\n", i);
    //  printf("   *** Child process is done ***\n");

    exit(0);
    }

void  ParentProcess(void)
{
     int   i, pid, status;

     for (i=0; i < 2; i++){
       pid = wait(&status);
       printf("Child Pid: %d has completed\n", pid);
     }

    //  for (i = 1; i <= MAX_COUNT; i++)
    //       printf("This line is from parent, value = %d\n", i);
    //  printf("*** Parent is done ***\n");
}