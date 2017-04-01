#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define SIZE 5

enum state {THINKING, HUNGRY, EATING};
enum state curr[SIZE];
sem_t mutex;
sem_t self[SIZE];

void *philosopher(int i);
void putdown(int i);
void pickup(int i);
void test(int i);

int main(){
	int i;
	sem_init(&mutex, 0, 1);
	for(i=0; i<SIZE; i++)
		sem_init(&self[i], 0, 0);
	for(i=0; i<SIZE; i++){
		printf("Philosopher %d is THINKING\n",i);
		curr[i] = THINKING;
	}
	pthread_t x[SIZE];
	for(i=0; i<SIZE; i++){
		pthread_create(&x[i], NULL, &philosopher, i);
	}
	for(i=0; i<SIZE; i++)
		pthread_join(x[i], NULL);
	return 0;
}

void *philosopher(int i){
	while(1){
		sleep(1);
		pickup(i);
		sleep(1);
		putdown(i);	
	}
}

void pickup(int i){
	curr[i] = HUNGRY;	
	printf("Philosopher %d is HUNGRY\n",i);
	sleep(1);
	
	test(i);
	if(curr[i] != EATING)
		sem_wait(&self[i]);
}

void putdown(int i){
	curr[i] = THINKING;
	printf("Philosopher %d is THINKING\n",i);
	sleep(1);

	test((i+SIZE-1)%SIZE);	
	test((i+1)%SIZE);
}

void test(int i){
	sem_wait(&mutex);
	if(curr[i] == HUNGRY && curr[(i+1)%SIZE] != EATING && curr[(i+SIZE-1)%SIZE] != EATING){
		printf("Philosopher %d is EATING\n",i);
		curr[i] = EATING;
		sleep(1);
		sem_post(&self[i]);	
	}
	sem_post(&mutex);
}
