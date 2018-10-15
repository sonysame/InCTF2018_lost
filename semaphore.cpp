#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


sem_t semaphore;
int num=2;

void * threadF1(void * arg){
	int i;
	if(num!=0){
		num--;
		sem_wait(&semaphore);
		printf("start thread 1 use\n");
		for(i=0;i<1000000;i++){}
		printf("end thread 1 use\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num==0){
		printf("thread 1 is waiting\n");
		while(num==0){}
		printf("end thread 1 use\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void * threadF2(void * arg){
	int i;
	if(num!=0){
		num--;
		sem_wait(&semaphore);
		printf("start thread 2 use\n");
		for(i=0;i<1000000;i++){}
		printf("end thread 2 use\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num==0){
		printf("thread 2 is waiting\n");
		while(num==0){}
		printf("end thread 2 use\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void * threadF3(void * arg){
	int i;
	if(num!=0){
		num--;
		sem_wait(&semaphore);
		printf("start thread 3 use\n");
		for(i=0;i<1000000;i++){}
		printf("end thread 3 use\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num==0){
		printf("thread 3 is waiting\n");
		while(num==0){}
		printf("end thread 3 use\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

int main(){
	pthread_t thread1, thread2, thread3;

	sem_init(&semaphore, 0, 2);//sem_init(sem_t *sem, int pshared, unsigned value), if pshared is not 0, processes can share resources, if pshared is 0, threads within process can share semaphore, value is defalut value for initialized semaphore

	printf("Semaphore test Start!\n");

	//create thread
	pthread_create(&thread1, NULL, threadF1, NULL);
	pthread_create(&thread2, NULL, threadF2, NULL);
	pthread_create(&thread3, NULL, threadF3, NULL);

	//join thread
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("All threads terminate\n");

	sem_destroy(&semaphore); //destory semaphore object

	return 0;
}