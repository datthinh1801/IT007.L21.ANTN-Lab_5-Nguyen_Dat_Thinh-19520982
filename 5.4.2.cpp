/*#######################################
# University of Information Technology  #
# IT007 Operating System                #
# Nguyen Dat Thinh                      #
# 19520982                              #
# File: 5.4.2.cpp                       #
########################################*/

#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#include <time.h>
#include <random>
using namespace std;

sem_t sem;
pthread_mutex_t mutex;
vector<int> a;

void *generate(void *mess)
{
	while (true)
	{
		pthread_mutex_lock(&mutex);
		a.push_back(rand());
		cout << "[after add] " << a.size() << endl;
		pthread_mutex_unlock(&mutex);

		sem_post(&sem);
	}
}

void *extract(void *mess)
{
	while (true)
	{
		sem_wait(&sem);

		pthread_mutex_lock(&mutex);
		int i = rand() % a.size();
		a.erase(a.begin() + i);
		cout << "[after remove] " << a.size() << endl;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	srand(time(0));

	sem_init(&sem, 0, 0);
	pthread_mutex_init(&mutex, NULL);

	pthread_t p_gen, p_ext;
	pthread_create(&p_gen, NULL, &generate, NULL);
	pthread_create(&p_ext, NULL, &extract, NULL);
	while (true)
		;
	return 0;
}
