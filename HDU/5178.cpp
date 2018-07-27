#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

int map[30][30];
int p,q;
int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
int flag;
struct pp
{
	int x,y,pa;
}s[1000];

void print(int u)
{
	if(s[u].pa!=-1)
		print(s[u].pa);
	printf("%c%d",s[u].x-1+'A',s[u].y);
}

void dfs(int sx,int sy,int cnt,int par)
{
	if(flag) return ;
	printf("???\n");
	if(cnt==q*p){
		flag=1;
		print(par);
		return ;
	}
	int i,xx,yy;
	for(i=0;i<8;i++){
		if(flag)
			return ;
		xx=sx+dx[i];yy=sy+dy[i];
		if(xx>0 && yy>0 && xx<=q && yy<=p && !map[xx][yy]){
			map[xx][yy]=1;
			s[i+1].x=xx;s[i+1].y=yy;s[i+1].pa=par;
			dfs(xx,yy,cnt+1,i+1);
			map[xx][yy]=0;
		}
	
	}
}



int main()
{
	int T,i,j,k,kcase=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&p,&q);
		printf("Scenario #%d:\n",kcase++);
/*		for(i=1;i<=q;i++){
			for(j=1;j<=p;j++){
				memset(map,0,sizeof(map));
				map[i][j]=1;s[0].x=i;s[0].y=j;s[0].p=-1;
				flag=0;
				dfs(i,j,1,0);
				if(flag)
					break;
			}
			if(flag) break;
		}*/
		memset(map,0,sizeof(map));
		map[0][0]=1;s[0].x=i;s[0].y=j;s[0].pa=-1;
		flag=0;
		dfs(1,1,1,0);
		if(!flag)
			printf("impossible");
		printf("2\n");
	}
	return 0;
}