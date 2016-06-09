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
	int shmid;
	key_t key;
	char sign;
	char *shm;
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
	int i = 0;
	do
	{
		sign = rand()%58+65;
		shm[i%SHM_SIZE] = sign;
		i++;
	}while(1);
	return 0;
 } 
