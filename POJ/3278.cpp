#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 2e8

int vis[2000010];
int n,k;

int bfs(int s)
{
	int t,res=0;
	queue<int> q;
	q.push(s);
	vis[s]=res;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t==k)
		{
			return vis[t];
		}
		if(t>0 && vis[t-1]==0)
		{
			vis[t-1]=vis[t]+1;
			q.push(t-1);
		}
		if(vis[t+1]==0)
		{
			vis[t+1]=vis[t]+1;
			q.push(t+1);
		}
		if(t<k && vis[t*2]==0)
		{
			vis[t*2]=vis[t]+1;
			q.push(t*2);
		}
	}
	return 0;
}




int main()
{
	int i,t;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		t=bfs(n);
		printf("%d\n",t);
	}
	return 0;
}

