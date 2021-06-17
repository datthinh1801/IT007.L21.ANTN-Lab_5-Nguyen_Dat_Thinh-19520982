/*#######################################
# University of Information Technology  #
# IT007 Operating System                #
# Nguyen Dat Thinh                      #
# 19520982                              #
# File: 5.5.cpp                       	#
########################################*/

#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#include <thread>
#include <chrono>
using namespace std;

int x1, x2, x3, x4, x5, x6, w, v, y, z, ans;
sem_t sem_b, sem_ac, sem_ad, sem_ef;

void *processA(void *mess)
{
	w = x1 * x2;
	sem_post(&sem_ac);
	sem_post(&sem_ad);
}

void *processB(void *mess)
{
	v = x3 * x4;
	sem_post(&sem_b);
	sem_post(&sem_b);
}

void *processC(void *mess)
{
	sem_wait(&sem_b);
	y = v * x5;
	sem_post(&sem_ac);
}

void *processD(void *mess)
{
	sem_wait(&sem_b);
	z = v * x6;
	sem_post(&sem_ad);
}

void *processE(void *mess)
{
	sem_wait(&sem_ac);
	sem_wait(&sem_ac);
	y = w * y;
	sem_post(&sem_ef);
}

void *processF(void *mess)
{
	sem_wait(&sem_ad);
	sem_wait(&sem_ad);
	z = w * z;
	sem_post(&sem_ef);
}

void *processG(void *mess)
{
	sem_wait(&sem_ef);
	sem_wait(&sem_ef);
	ans = y + z;
	cout << ans << endl;
}

int main()
{
	sem_init(&sem_b, 0, 0);
	sem_init(&sem_ac, 0, 0);
	sem_init(&sem_ad, 0, 0);
	sem_init(&sem_ef, 0, 0);

	x1 = 1;
	x2 = 2;
	x3 = 3;
	x4 = 4;
	x5 = 5;
	x6 = 6;

	pthread_t p_A, p_B, p_C, p_D, p_E, p_F, p_G;

	pthread_create(&p_A, NULL, &processA, NULL);
	pthread_create(&p_B, NULL, &processB, NULL);
	pthread_create(&p_C, NULL, &processC, NULL);
	pthread_create(&p_D, NULL, &processD, NULL);
	pthread_create(&p_E, NULL, &processE, NULL);
	pthread_create(&p_F, NULL, &processF, NULL);
	pthread_create(&p_G, NULL, &processG, NULL);

	this_thread::sleep_for(std::chrono::seconds(1));
	return 0;
}