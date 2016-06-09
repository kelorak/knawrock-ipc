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
	int *shm;
	int shmid;

	key_t key;
	time_t start;
	time_t stop;
	double runtime;
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
	start = time(NULL);
	int i;
	for(i = 0; i < SHM_SIZE; i++)
	{
		printf("%d\n", shm[i])
	}
	exit(1);
	return 0;
}
