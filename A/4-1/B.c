
Semaphore NotFull = 1, NotEmpty = 0, Listmutex = 1;
int count = 0;
In:
	while(1)
	{
		P(NotFull);   // 座位未作坐满
		P(Listmutex);  
		if(count==0)
		{
			V(NotEmpty);    //如果有人了，则图书馆非空
		}
		++count;
		Regist();
		if(count<100)
		{
			V(NotFull);//若未坐满,则还可以再坐,否则,座位就满了就不释放
		}
		V(Listmutex);
	}

Out:
	while(1)
	{
		P(NotEmpty);         //图书馆有人，才会有人可以出去。
		P(Listmutex);
		if(count==100)
		{
			V(NotFull);      //座位又出现未满状况，释放
		}
		--count;
		Unregist();
		if(count>0)
		{
			V(NotEmpty);//非空才可以有人继续出去,否则就不存在有人能出去。
		}
		V(Listmutex);
	}