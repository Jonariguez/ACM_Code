#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxl=40;

typedef struct pp
{
	int x,y,z,cnt;
}point;

char map[maxl][maxl][maxl];
int vis[maxl][maxl][maxl];
int sx,sy,sz,ex,ey,ez,L,R,C;

int bfs(){
	int i;
	memset(vis,0,sizeof(vis));
	point s;
	s.x=sx;s.y=sy;s.z=sz;
	s.cnt=0;
	map[sz][sy][sx]='#';		//一定注意这里对应的是sz,sy,sx，而不是sx,sy,sz!!!
	queue<point> que;
	que.push(s);
	while(!que.empty()){
		point t=que.front();
		if(t.x==ex && t.y==ey && t.z==ez) return t.cnt;
		que.pop();
		for(i=-1;i<=1;i+=2)
			if(t.x+i>=1 && t.x+i<=C && map[t.z][t.y][t.x+i]!='#'){
			//	if(map[t.z][t.y][t.x+i]=='E') return t.cnt+1;
				point tt;
				tt.x=t.x+i;tt.y=t.y;tt.z=t.z;tt.cnt=t.cnt+1;
				map[tt.z][tt.y][tt.x]='#';
				que.push(tt);
			}
		for(i=-1;i<=1;i+=2)
			if(t.y+i>=1 && t.y+i<=R && map[t.z][t.y+i][t.x]!='#'){
			//	if(map[t.z][t.y+i][t.x]=='E') return t.cnt+1;
				point tt;
				tt.x=t.x;tt.y=t.y+i;tt.z=t.z;tt.cnt=t.cnt+1;
				map[t.z][t.y+i][t.x]='#';
				que.push(tt);
			}
		for(i=-1;i<=1;i+=2)
			if(t.z+i>=1 && t.z+i<=L && map[t.z+i][t.y][t.x]!='#'){
			//	if(map[t.z+i][t.y][t.x]=='E') return t.cnt+1;
				point tt;
				tt.x=t.x;tt.y=t.y;tt.z=t.z+i;tt.cnt=t.cnt+1;
				map[t.z+i][t.y][t.x]='#';
				que.push(tt);
			}
	}
	return 0;
}






int main()
{
	int i,j,k,t,res;
	while(scanf("%d%d%d",&L,&R,&C)){
		if(L==0 && R==0 && C==0) break;
		for(i=1;i<=L;i++){	//z
			for(j=1;j<=R;j++)	//y
				for(k=1;k<=C;k++){	//x
					scanf(" %c",&map[i][j][k]);
					if(map[i][j][k]=='S'){
						sx=k;sy=j;sz=i;
					}
					if(map[i][j][k]=='E'){
						ex=k;ey=j;ez=i;
					}
				}
			getchar();getchar();
		}
		res=bfs();
		if(res==0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",res);
	}
	return 0;
}
