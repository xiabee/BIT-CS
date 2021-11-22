int findm( int n, int price[][3], BUY scheme[] )
{
	int min = 100000000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ; j  < n; j++)
		{
			for (int k = 0; k < n; k++)
			{ 
	if (i == j || i == k || k == j)
	 continue;
	else
	{
	 int temp = price[i][0] + price[j][1] + price[k][2];
	 if (temp < min)
	 {
	  scheme[0].sname = i+1;
	  scheme[1].sname = j+1;
	  scheme[2].sname = k+1;
	  
	  scheme[0].gprice = price[i][0];
	  scheme[1].gprice = price[j][1];
	  scheme[2].gprice = price[k][2];
	  min = temp; 
	 }  
	}

			}
		}
	}
	return min;
}