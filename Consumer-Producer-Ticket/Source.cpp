#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Producer.h"
#include "Consumer.h"
std::mutex* producerLock = new std::mutex;
std::mutex* consumerLock = new std::mutex;

int main() {

	Globals::initDataBuffer();
	std::vector<std::thread*> consumerThreads;
	std::vector<std::thread*> producerThreads;

	for (int i = 0; i < 5; i++)
	{
		Producer p(producerLock);
		Consumer c(consumerLock);

		std::thread producerThread(&Producer::producer, p);
		std::thread consumerThread(&Consumer::consumer, c);

		producerThread.detach();
		consumerThread.detach();

		producerThreads.push_back(&producerThread);
		consumerThreads.push_back(&consumerThread);
	}
	while (true)
	{
		// Gameplay Loop
	}
	return 0;
}