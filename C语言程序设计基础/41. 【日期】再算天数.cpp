int main()
{
	int y1, m1, d1, y2, m2, d2;
	scanf ("%d %d %d", &y1, &m1, &d1);
	scanf ("%d %d %d", &y2, &m2, &d2);
	int dy = 0, dy1, dy2;
	for(int i = y1; i <= y2; i++)
	{
		if (leap_year(i)) dy = dy + 366;
		else dy = dy + 365;
	}
	dy1 = days(y1, m1, d1);
	dy2 = year_days(y2) - days(y2, m2, d2);
	
	int dd = dy - dy1 - dy2;
	if (dd != 1) printf ("%d days\n", dd);
	else printf ("1 day\n");
}