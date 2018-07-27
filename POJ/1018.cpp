#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;
#define INF 1e4

int a[101][101];
int b[101][101];
int p[101][101];
int m[101];
ll sump,n;
double res;

void dfs(int cur,int minb,int pp)
{
	sump+=pp;
	if(cur==n)
	{
		if(res<(double)minb/sump)
			res=(double)minb/sump;
		return ;
	}
	int i;
	for(i=0;i<m[cur];i++)
	{
		if(minb<b[cur][i])
			dfs(cur+1,minb,p[cur][i]);
		else
			dfs(cur+1,b[cur][i],p[cur][i]);
	}
}





int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
			for(j=0;j<m[i];j++)
				scanf("%d%d",&b[i][j],&p[i][j]);
		}
		for(i=0;i<n;i++)
			printf("%d ",m[i]);
		sump=0;res=0;
		dfs(0,INF,0);
		printf("%.3f\n",res);
	}
	return 0;
}
