#include "Consumer.h"
#include <iostream>

Consumer::Consumer(std::mutex* sharedLock)
{
	this->sharedLock = sharedLock;
	myId = nextId;
}

Consumer::~Consumer()
{
}

void Consumer::consumeData(int data, int pos) 
{
	std::cout << "ID: " << myId << ", consumed burger number: " << data << " at buffer pos: " << pos << "\n";

}

// consumer thread function
void Consumer::consumer() {

	while (true)
	{
		int consumerTicket = Globals::nextTicket++;
		while (Globals::dataBuffer[Globals::front] != consumerTicket)
		{
			//std::cout << "waiting..." << "\n";
			//sharedLock->unlock();
			continue;
		}

		sharedLock->lock();
		std::cout << "ID: " << myId << ", collected burger ticket number: " << consumerTicket << "\n";
		Globals::dataBuffer[Globals::front] = -1;
		Globals::front = (Globals::front + 1) % Globals::MAX_BUFFER_SIZE;
		Globals::availableSlots++;
		sharedLock->unlock();
	}
}
int Consumer::nextId = 0;

