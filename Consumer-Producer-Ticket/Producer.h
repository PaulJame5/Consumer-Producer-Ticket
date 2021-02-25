#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"


class Producer
{
public:
	Producer(std::mutex* sharedLock);
	~Producer();

	int produceData(int pos);
	void producer();

	std::mutex *sharedLock;
	int myId = 0;
private:
	static int nextId;
};