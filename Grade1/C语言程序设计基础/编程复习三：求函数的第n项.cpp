int sumn(int n, int *flag)
{ 
	if (n >= 1)
	{
		(*flag)++;
		return sumn(n - 1, flag) + n*(n+1); 
	}
	else return 0; 

}