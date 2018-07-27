#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct pp
{
	int x,y,cnt;
};

int ldx[4][4]={
	{-1,0,1,0},
	{1,0,-1,0},
	{0,-1,0,1},
	{0,1,0,-1}
},
ldy[4][4]={
	{0,-1,0,1},
	{0,1,0,-1},
	{1,0,-1,0},
	{-1,0,1,0}
},
rdx[4][4]={
	{1,0,-1,0},
	{-1,0,1,0},
	{0,-1,0,1},
	{0,1,0,-1}
},
rdy[4][4]={
	{0,-1,0,1},
	{0,1,0,-1},
	{-1,0,1,0},
	{1,0,-1,0}
};

char map[45][45];
int vis[45][45],ex,ey,h,w,flag;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int dfsl(int sx,int sy,int cnt,int dir)
{
	int i,xx,yy;
	for(i=0;i<4;i++){
		xx=sx+ldx[dir][i];yy=sy+ldy[dir][i];
		if(xx==ex && yy==ey)
			return cnt+1;
		if(xx>=0 && yy>=0 && xx<w && yy<h && map[yy][xx]!='#'){
			if(xx==sx){
				if(yy-sy==1) return dfsl(xx,yy,cnt+1,1);
				else return dfsl(xx,yy,cnt+1,0);
			}
			else {
				if(xx-sx==1) return dfsl(xx,yy,cnt+1,3);
				else return dfsl(xx,yy,cnt+1,2);
			}
		}
	}
}

int dfsr(int sx,int sy,int cnt,int dir)
{
	int i,xx,yy;
		for(i=0;i<4;i++){
		xx=sx+rdx[dir][i];yy=sy+rdy[dir][i];
		if(xx==ex && yy==ey)
			return cnt+1;
		if(xx>=0 && yy>=0 && xx<w && yy<h && map[yy][xx]!='#'){
			if(xx==sx){
				if(yy-sy==1) return dfsr(xx,yy,cnt+1,1);
				else return dfsr(xx,yy,cnt+1,0);
			}
			else {
				if(xx-sx==1) return dfsr(xx,yy,cnt+1,3);
				else return dfsr(xx,yy,cnt+1,2);
			}
		}
	}
}

int bfs(int sx,int sy)
{
	int i,xx,yy;
	pp s,t;
	s.x=sx;s.y=sy;s.cnt=1;
	queue<pp> q;
	q.push(s);
	map[sy][sx]='#';
	while(!q.empty()){
		t=q.front();q.pop();
		for(i=0;i<4;i++){
			xx=t.x+dx[i];yy=t.y+dy[i];
			if(xx==ex && yy==ey) return t.cnt+1;
			if(xx>=0 && yy>=0 && xx<w && yy<h && map[yy][xx]!='#'){
				pp tt;
				tt.x=xx;tt.y=yy;tt.cnt=t.cnt+1;q.push(tt);
				map[yy][xx]='#';
			}
		}
	}
}



int main()
{
	int i,j,k,T,sx,sy,d,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&w,&h);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++){
				scanf(" %c",&map[i][j]);
				if(map[i][j]=='S'){
					sx=j;sy=i;
					if(i==0) d=1;
					else if(j==0) d=3;
					else if(j==w-1) d=2;
					else if(i==h-1) d=0;
				}
				else if(map[i][j]=='E'){
					ex=j;ey=i;
				}
			}			
			ans=dfsl(sx,sy,1,d);
			printf("%d ",ans);
			printf("%d ",dfsr(sx,sy,1,d));
			printf("%d\n",bfs(sx,sy));
	}
	return 0;
}


