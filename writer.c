#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>
#define SHM_SIZE 100
int main()
{
	srand (time(NULL));
	a = 1;
	q = 2;
	int shmid;
	key_t key;
	int *shm;
	key = 6666;
	shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
	if(shmid == -1)
	{
		perror("shmget error\n");
		exit(1);
	}
	shm = shmat(shmid, NULL, 0);
	if(shm == NULL)
	{
		perror("shmat error\n");
		exit(1);
	}
	int i;
	for(i = 1; i < SHM_SIZE; i++)
	{
		a = a*q;
		shm[i] = a;
	}
	return 0;
 } 
