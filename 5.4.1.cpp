/*#######################################
# University of Information Technology  #
# IT007 Operating System                #
# Nguyen Dat Thinh                      #
# 19520982                              #
# File: 5.4.1.cpp                       #
########################################*/

#include <pthread.h>
#include <iostream>
#include <semaphore.h>
using namespace std;

int sells = 0, products = 0;
sem_t sem_1, sem_2;

void *sell(void *mess)
{
	while (true)
	{
		sem_wait(&sem_1);
		++sells;
		sem_post(&sem_2);
		cout << "sells = " << sells << endl;
	}
}

void *produce(void *mess)
{
	while (true)
	{
		sem_wait(&sem_2);
		++products;
		sem_post(&sem_1);
		cout << "products = " << products << endl;
	}
}

int main()
{
	sem_init(&sem_1, 0, 0);
	sem_init(&sem_2, 0, 92);

	pthread_t p_sell, p_product;

	pthread_create(&p_sell, NULL, &sell, NULL);
	pthread_create(&p_product, NULL, &produce, NULL);

	while (true)
		;
	return 0;
}