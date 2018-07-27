#include <stdio.h>
#include <string.h>
#include <math.h>

struct pp
{
	int row,col;
	int p;
}s[20];


int a[6][6];	//0:open   1: close
int step,f;

void print(int n)
{
	if(s[n].p!=-1)
		print(s[n].p);
	printf("%d %d\n",s[n].row,s[n].col);
}

int check()
{
	int i,j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			if(a[i][j])
				return 0;
	return 1;
}

void shift(int x,int y)
{
	int i;
	for(i=1;i<=4;i++)
	{
		a[i][y]=!a[i][y];
		a[x][i]=!a[x][i];
	}
	a[x][y]=!a[x][y];
}

void dfs(int x,int y,int cur)
{
	if(cur==step)
	{
		f=check();
		return ;
	}
	if(f || x==5)
		return ;
	shift(x,y);
	s[cur].row=x;s[cur].col=y;
	s[cur+1].p=cur;
	if(y<4)
		dfs(x,y+1,cur+1);
	else
		dfs(x+1,1,cur+1);
	shift(x,y);
	if(y<4)
		dfs(x,y+1,cur);
	else
		dfs(x+1,1,cur);
	return ;
}





int main()
{
	int i,j,k,n;
	char c;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
		{
			scanf(" %c",&c);
			if(c=='+')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	for(i=0;i<20;i++)
		s[i].p=-1;
	f=0;
	for(step=0;step<=16;step++)
	{
		
		dfs(1,1,0);
		if(f)
			break;
	}
//	printf("f=%d\n",f);
	if(f)
	{
		printf("%d\n",step);
		print(step-1);
	}
	else
		printf("0\n");
	return 0;
}






