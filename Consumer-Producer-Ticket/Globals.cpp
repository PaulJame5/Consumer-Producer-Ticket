#include "Globals.h"


Globals::Globals()
{
}

Globals::~Globals()
{
}

void Globals::initDataBuffer()
{
	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		dataBuffer[i] = -1;
	}
}

int Globals::dataBuffer[MAX_BUFFER_SIZE];
int Globals::availableSlots = MAX_BUFFER_SIZE;
int Globals::front = 0;
int Globals::back = 0;
int Globals::currentTicket = 0;
int Globals::nextTicket = 0;