int isprime(int x)
{
	if(x<=1)
		return 0;
	if(x==2)
		return 1;
	int i;
	for(i=2; i<x; i++)
		if(x%i==0)
			return 0;
	return 1;
}

