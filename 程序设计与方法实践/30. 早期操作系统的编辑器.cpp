#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct qnmd//思来想去还是用链表吧
{
	char str[100];
	struct qnmd* next;
}nmd;

char temp_s[100], m[100], n[100], input_c, temp_temp[100];
int v, i, j, t = 0, r = 0, count = 0, m1, n1, temp1, temp2, l, flag = 0;
nmd* p, * q, * head;
char ch;
FILE* vvv;
int main()
{
	vvv = freopen("input.txt", "r", stdin);
	v = scanf("%s",temp_s);//读入[Text],没有gets就很gg
	p = head = (nmd*)malloc(sizeof(nmd));
	while (1)
	{
		i = 0;
		while ((ch = getchar()) != '\n')
			v = scanf("%c", &temp_s[i++]);//VS没有gets就很迷
		if (!strcmp(temp_s, "[/Text]"))//遇到[/Text]
			break;
		q = (nmd*)malloc(sizeof(nmd));
		if (p && q)//You must allocate memory inside the function...VS
		{
			p->next = q;
			strcpy(q->str, temp_s);
			q->next = NULL;
			p = q;
			count++;
		}
	}//读入
	while (scanf("%c ", &input_c) != EOF)//读入操作符
	{
		if (input_c == 'i')
		{
			v = scanf("%d/%[^\n]", &m1, temp_s);
			if (m1 > count)
			{
				for (p = head; p->next != NULL; p = p->next);
				q = (nmd*)malloc(sizeof(nmd));
				strcpy(q->str, temp_s);
				p->next = q;
				q->next = NULL;
				count++;
			}
			else
			{
				p = head;   i = 1;
				while (i < m1)
				{
					p = p->next;
					i++;
				}
				q = (nmd*)malloc(sizeof(nmd));
				strcpy(q->str, temp_s);
				q->next = p->next;
				p->next = q;
				count++;
			}
		}
		if (input_c == 'd')
		{
			v = scanf("%d", &m1);
			p = head;  i = 1;
			while (i < m1)
			{
				p = p->next;
				i++;
			}
			p->next = p->next->next;
			free(p->next);
			count--;
		}
		if (input_c == 'f')
		{
			v = scanf("%d/%d", &m1, &n1);
			p = head->next;
			q = head;
			i = 1;
			while (i < m1)
			{
				p = p->next; i++;
			}
			i = 1;
			while (i < n1)
			{
				q = q->next;
				i++;
			}
			strcat(p->str, q->next->str);
			q->next = q->next->next;
			free(q->next);
			count--;
		}
		if (input_c == 'c')
		{
			v = scanf("%[^\n]", temp_s);
			t = 0; r = 0;
			for (i = 0; temp_s[i] != '\0'; i++)
			{
				if (temp_s[i] != '\\' && temp_s[i + 1] == '/')
					temp_s[i + 1] = '\0';

				j = i + 2;
			}
			for (i = 0; temp_s[i] != '\0'; i++)
			{
				if (temp_s[i] != '\\')
					m[t++] = temp_s[i];
				else
				{
					m[t++] = temp_s[i + 1];
					i++;
				}
			}
			m[t] = '\0';
			for (i = j; temp_s[i] != '\0'; i++)
			{
				if (temp_s[i] != '\\')
					n[r++] = temp_s[i];
				else
				{
					n[r++] = temp_s[i + 1];
					i++;
				}
			}
			n[r] = '\0';
			temp1 = strlen(m); temp2 = strlen(n);
			t = 0; r = 0;
			memset(temp_temp, 0, sizeof(temp_temp));
			for (p = head->next, r = 1; r <= count; p = p->next, r++)
			{
				t = 0;
				for (i = 0; p->str[i] != '\0'; i++)
				{
					if (p->str[i] != m[0])
					{
						temp_temp[t++] = p->str[i];
						temp_temp[t] = '\0';
					}
					else
					{
						for (j = 0; j < temp1; j++)
							if (p->str[i + j] != m[j])
							{
								flag = 0; break;
							}
						if (j == temp1)
							flag = 1;
						if (flag == 1)
						{
							strcat(temp_temp, n);
							i = i + temp1 - 1;
							t = t + temp2;
						}
						else
						{
							temp_temp[t++] = p->str[i];
							temp_temp[t] = '\0';
						}


					}
				}
				strcpy(p->str, temp_temp);
				memset(temp_temp, 0, sizeof(temp_temp));
			}
		}

	}
	ch = getchar();
	for (p = head->next, r = 1; r <= count; p = p->next, r++)
		printf("%s\n", p->str);
	memset(temp_temp, 0, sizeof(temp_temp));
	return 0;
}