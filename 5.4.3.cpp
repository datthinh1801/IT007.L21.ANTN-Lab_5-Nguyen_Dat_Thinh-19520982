/*#######################################
# University of Information Technology  #
# IT007 Operating System                #
# Nguyen Dat Thinh                      #
# 19520982                              #
# File: 5.4.3.cpp                       #
########################################*/

#include <pthread.h>
#include <iostream>
using namespace std;

int x = 0;

void *processA(void *mess)
{
	while (true)
	{
		x = x + 1;
		if (x == 20)
			x = 0;
		cout << "x = " << x << endl;
	}
}

void *processB(void *mess)
{
	while (true)
	{
		x = x + 1;
		if (x == 20)
			x = 0;
		cout << "x = " << x << endl;
	}
}

int main()
{
	pthread_t p1, p2;
	pthread_create(&p1, NULL, &processA, NULL);
	pthread_create(&p2, NULL, &processB, NULL);
	while (true)
		;
	return 0;
}
