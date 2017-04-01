#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5

pthread_mutex_t mutex;
sem_t empty;
sem_t full;
int buffer[SIZE];
int in, out;

void *producer(void);
void *consumer(void);

int main(){
	sem_init(&empty,0,SIZE);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex, NULL);
	
	in = 0;
	out = 0;


	pthread_t pro;
	pthread_t cons;
	
	pthread_create(&pro, NULL, &producer, NULL);
	pthread_create(&cons, NULL, &consumer, NULL);

	pthread_join(pro,NULL);
	pthread_join(cons, NULL);	
	return 0;
}

void *producer(void){
	int v;
	while(1){
		sleep(rand()%10);
		v = rand() % 100;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[out] = v;
		out = (out + 1) % SIZE;
		printf("Producer produced %d\n",v);
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	pthread_exit(0);
}

void *consumer(void){
	int v;
	while(1){
		sleep(rand()%10);
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		v = buffer[in];
		in = (in + 1) % SIZE;
		printf("Consumer consumed %d\n",v);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	pthread_exit(0);

}
