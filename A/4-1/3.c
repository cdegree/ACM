
Semaphore wakeup = 0, prepare_for_hair_cut = 0, mutex = 1;

int nchair = n ;
int wait_count = 0 ;

Barber:
	while(1)
	{
		P(wakeup);
		P(mutex);
		--wait_count;
		if(wait_count>0)
		{
			V(wakeup);  //如果还有人，则保持清醒状态。
		}
		V(mutex);
		V(prepare_for_hair_cut);
		have_hair_cut();
	}

Customer:
	while(1)
	{
		P(mutex);
		if(wait_count<nchair)
		{
			if(wait_count==0)
			{
				V(wakeup);  //如果理发师是睡着的，则唤醒他。
			}
			++wait_count;
			V(mutex);
			P(prepare_for_hair_cut);
			get_hair_cutted();
		}
		else 
		{
			V(mutex);
		}
	}