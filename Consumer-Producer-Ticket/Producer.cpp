#include "Producer.h"
#include <iostream>

Producer::Producer(std::mutex * sharedLock)
{
	this->sharedLock = sharedLock;
	myId = nextId++;
}

Producer::~Producer()
{
}

int Producer::produceData(int pos) {
	static int burgerNumber = 0;

	std::cout << "ID: " << myId << ", produced burger number: " << burgerNumber << " at buffer pos: " << Globals::back << "\n";
	burgerNumber++;
	return burgerNumber;
}


void Producer::producer() {
	while (true) {

		sharedLock->lock();
		if (Globals::availableSlots < 1)
		{
			//std::cout << "spinning producer" << "\n";
			if (Globals::availableSlots < 0)
			{
				Globals::availableSlots = 0;
			}
			sharedLock->unlock();
			continue;
		}
		Globals::dataBuffer[Globals::back] = Globals::currentTicket; 
		std::cout << "ID: " << myId << ", produced burger for ticket number: " << Globals::dataBuffer[Globals::back] << "\n";
		Globals::currentTicket++;
		Globals::back = (Globals::back + 1) % Globals::MAX_BUFFER_SIZE;
		Globals::availableSlots--;
		sharedLock->unlock();
	}
}
int Producer::nextId = 0;

