#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main() 
{
   int key = ftok("shm",2);
   int shmid = shmget(key,1024,0666 | IPC_CREAT);
   char * shmaddr = shmat(shmid,NULL,0);
   printf("data read from shared memoery in reader pocess: \n");
   puts(shmaddr);
   exit(0);   
}