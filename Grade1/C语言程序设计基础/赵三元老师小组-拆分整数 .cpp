int count(int n, int m)
{
	if (n < 1 || m < 1) return 0;
	else if (n == 1 || m == 1) return 1;
	else if (m > n) return count(n, n);
	else if (n == m) return count(n, n-1) + 1;
	else return count(n-m, m) + count(n, m-1);
}