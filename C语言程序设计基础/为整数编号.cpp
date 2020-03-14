int number(char * str, DATA a[])
{
	int n = 0, c[105] = {0}, c2[105] = {0};
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{ 
			int temp = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
	temp = temp * 10 + str[i] - '0';
	i++;
			}
			c[n++] = temp;
		}
		else if (str[i] == '-')
		{
			i++;
			int temp = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
	temp = temp * 10 + str[i] - '0';
	i++;
			}
			c[n++] = -temp;  
		}
	}
	
	for (int i = 0; i < n; i++)
		c2[i] = c[i];
		
	for (int i = 0; i < n; i++) //c2 up
	{
		for (int j = 0; j + 1 < n - i; j++)
		{
			if (c2[j + 1] <= c2[j])
			{
	int temp;
	temp = c2[j];
	c2[j] = c2[j + 1];
	c2[j + 1] = temp;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i] == c2[j])
			{
	a[i].num = c[i];
	a[i].no = j + 1;
	c2[j] = -10000;
	break;
			}
		}
	}
	return n;

}