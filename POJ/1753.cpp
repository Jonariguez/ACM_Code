#include <stdio.h>
#include <string.h>
#include <math.h>

int a[6][6];
int step,f;

int check()
{
	int i,j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			if(a[i][j]!=a[1][1])
				return 0;
	return 1;
}

void flip(int x,int y)
{
	a[x-1][y]=!a[x-1][y];
	a[x+1][y]=!a[x+1][y];
	a[x][y]=!a[x][y];
	a[x][y+1]=!a[x][y+1];
	a[x][y-1]=!a[x][y-1];
}

void dfs(int x,int y,int deep)
{

	if(deep==step)
	{
		if(check())
			f=1;
		return ;
	}
	if(f || y>=5 || x>=5)
		return ;
	flip(x,y);
	if(y<4)
		dfs(x,y+1,deep+1);
	else
		dfs(x+1,1,deep+1);
	flip(x,y);
	if(y<4)
		dfs(x,y+1,deep);
	else
		dfs(x+1,1,deep);
	
	return ;
}

int main()
{
	int i,j;
	char c;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
		{
			scanf(" %c",&c);
			if(c=='b')
				a[i][j]=1;
			else 
				a[i][j]=0;
		}
	f=0;
	if(check())
	{
		printf("0\n");
		return 0;
	}
	for(step=1;step<=16;step++)
	{
		dfs(1,1,0);
		if(f)
			break;
	}
	if(f)
		printf("%d\n",step);
	else
		printf("Impossible\n");
	return 0;
}

