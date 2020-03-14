int countsub( char *str, char *ss )
{
	int i, tot = 0, len = 0;
	for (int j = 0; str[len] != '\0'; len++);
	for (i = 0; str[i] != '\0'; i++)
	{ 
		int ok = 1, r = 0;
		for (int j = 0; ss[j] != '\0'; j++)
		{
			if (str[i+j] != ss[j])
	ok = 0;
		}
		while (ok)
		{ 
			r++;
			//printf ("i = %d r = %d\n", i, r);
			ok = 1;
			if (i + 3 < len)
	i = i + 3;
			else break;
			for (int j = 0; ss[j] != '\0' && str[i+j] != '\0'; j++)
			{
	if (str[i+j] != ss[j])
	 ok = 0;
			}
		}
		if (r > tot)
			tot = r;
	}
	return tot;
}