#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"


class Consumer
{
public:
	Consumer(std::mutex* sharedLock);
	~Consumer();

	void consumeData(int data, int pos);
	void consumer();
	std::mutex* sharedLock;
	int myId = 0;

private:
	static int nextId;

};