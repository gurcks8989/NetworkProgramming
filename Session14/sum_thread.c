#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *work_thread(void * arg); 

int num_threads;
int max_num; 

int main(int argc, char *argv[])
{
	pthread_t *thread;
	int *index; 
	int sum = 0;
	int i ;

	printf("Number of threads: ");
	scanf("%d", &num_threads);
	printf("Maximum integer (> Number of threads):");
	scanf("%d", &max_num);

	// TODO: pthread & index array
	thread = (pthread_t*) malloc(max_num * num_threads);
	index = (int*) malloc(max_num);

	// TODO: pthread create
	for (i = 0; i < num_threads; i++)
	{
		pthread_create(&thread[i], NULL, work_thread, (void *)&i);
	}

	// TODO: pthread_join
	int k = 0 ;
	for (i = 0; i < num_threads; i++)
	{
		pthread_join(thread[i], &*((void *)index)) ;
		for(int j = 0 ; j )
		sum += *(index) ;
		printf("Thread# %d: %d~%d Result=%d", i, k, *index, sum) ;
		k = *index ;
	}
	printf("result: %d \n", sum);
	return 0;
}

void *work_thread(void *arg) 
{
	//
	int num = *((int*)arg);

	return *((void **)num);
}
