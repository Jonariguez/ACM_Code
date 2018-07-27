#include <stdio.h>
#include <string.h>

int q,p,flag,tot;
int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
int vis[30][30];

struct pp
{
	int x,y;
}s[100];
void dfs(int sx,int sy,int step)
{
	if(flag) return ;
	s[step].x=sx;s[step].y=sy;
	if(step==q*p){
		flag=1;
		return ;
	}
	int i,xx,yy;
	for(i=0;i<8;i++){
		if(flag) return ;
		xx=sx+dx[i];yy=sy+dy[i];
		if(xx>0 && yy>0 && xx<=q && yy<=p && !vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy,step+1);
			vis[xx][yy]=0;
		}
	}
}


int main()
{
	int T,kcase=1,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&p,&q);
		printf("Scenario #%d:\n",kcase++);
		flag=0;
		memset(vis,0,sizeof(vis));
		vis[1][1]=1;
		dfs(1,1,1);
		if(flag){
			for(i=1;i<=p*q;i++)
				printf("%c%d",s[i].x-1+'A',s[i].y);
		}
		else
			printf("impossible");
			printf("\n\n");
	}
}