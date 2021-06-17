/*#######################################
# University of Information Technology  #
# IT007 Operating System                #
# Nguyen Dat Thinh                      #
# 19520982                              #
# File: 5.4.4.cpp                       #
########################################*/

#include <pthread.h>
#include <iostream>
using namespace std;

int x = 0;
pthread_mutex_t mutex;

void *processA(void *mess)
{
	while (true)
	{
		pthread_mutex_lock(&mutex);
		x = x + 1;
		if (x == 20)
			x = 0;
		cout << "x = " << x << endl;
		pthread_mutex_unlock(&mutex);
	}
}

void *processB(void *mess)
{
	while (true)
	{
		pthread_mutex_lock(&mutex);
		x = x + 1;
		if (x == 20)
			x = 0;
		cout << "x = " << x << endl;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t p1, p2;

	pthread_create(&p1, NULL, &processA, NULL);
	pthread_create(&p2, NULL, &processB, NULL);
	while (true)
		;
	return 0;
}
