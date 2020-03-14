#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[100005][3];
int vvv, count = 0, k, i, j;
typedef struct nmd
{
	int v;
	int id;
}gift;
gift XZ[100005];
int mmp(const void* p1, const void* p2);
void output(int i);
void input(int k);
void operation(int k);
void pre(void);
int main()
{
	vvv = scanf("%d", &k);
	input(k);
	qsort(XZ, k, sizeof(XZ[0]), mmp);
	operation(k);
	return 0;
}

int mmp(const void* p1, const void* p2) 
{
	gift* c = (gift*)p1;
	gift* d = (gift*)p2;
	return d->v - c->v;
}

void output(int i) 
{
	if (p[i][0] != -1) 
		output(p[i][0]);
	printf(" %d", XZ[i].id + 1);
	return;
}

void input(int k)
{
	for (i = 0; i < k; i++)
	{
		vvv = scanf("%d", &XZ[i].v);
		XZ[i].id = i;
	}
}

void operation(int k)
{
	int i, j, m;
	for (i = 0; i < k; i++)
	{
		p[i][0] = -1;
		p[i][1] = 0;
		p[i][2] = -1;
	}
	m = k - 2;
	for (i = k - 1; i >= 0; i--)
		for (j = m; j >= 0; j--)
		{
			if (XZ[j].v >= XZ[i].v * 2)
			{
				count++;
				p[j][0] = i;
				p[j][1] = p[i][1] + 1;
				p[i][2] = 0;
				m = j - 1;
				break;
			}
			if (j == 0 && XZ[j].v < XZ[i].v * 2)
				goto xiao;
		}
xiao:
	pre();
}

void pre(void)
{
	int i;
	printf("%d\n", k - count);
	for (i = 0; i < k; i++)
	{
		if (p[i][1] == 0 && p[i][2] == -1)
		{
			printf("1 %d\n", XZ[i].id + 1);
			continue;
		}
		if (p[i][0] != -1 && p[i][2] != 0)
		{
			printf("%d", p[i][1] + 1);
			output(p[i][0]);
			printf(" %d\n", XZ[i].id + 1);
			continue;
		}
	}
	return;
}