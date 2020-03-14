int findf(int n)
{
	if (n >= 0 && n <= 4)
		return 1;
	else if(n % 2 == 0 && n > 4)
		return findf(n-1) + findf(n-3);
	else if (n % 2 != 0 && n > 4)
		return findf(n-2) + findf(n-4);
	else return -1;
}