
Semaphore ACmutex = 1, BDmutex = 1;
A,C:
	while(1)
	{
		P(ACmutex);
		Read();
		V(ACmutex);
	}

B,D:
	while(1)
	{
		P(BDmutex);
		Read();
		V(BDmutex);
	}
