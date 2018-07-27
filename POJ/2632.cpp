#include <stdio.h>
#include <string.h>
#include <math.h>

int vis[102][102];

struct robot
{
	int x,y;
	int dir;	//0ио 1об 2вС 3ср
}s[101];

int A,B;

int L(robot s,int a)
{
	vis[s.x][s.y]=0;
	if(s.dir==0) s.y--;
	else if(s.dir==1) s.y++;
	else if(s.dir==2) s.x++;
	else if(s.dir==3) s.x--;
	if(vis[s.x][s.y])
		return vis[s.x][s.y];
	vis[s.x][s.y]=a;
	return 0;
}

int R(robot s,int a)
{
	vis[s.x][s.y]=0;
	if(s.dir==0) s.y++;
	else if(s.dir==1) s.y--;
	else if(s.dir==2) s.x--;
	else if(s.dir==3) s.x++;
	if(vis[s.x][s.y])
		return vis[s.x][s.y];
	vis[s.x][s.y]=a;
	return 0;
}

int F(robot s,int a)
{
	vis[s.x][s.y]=0;
	if(s.dir==0) s.x--;
	else if(s.dir==1) s.x++;
	else if(s.dir==2) s.y--;
	else if(s.dir==3) s.y++;
	if(vis[s.x][s.y])
		return vis[s.x][s.y];
	vis[s.x][s.y]=a;
	return 0;
}


int check(robot s)
{
	if(s.x<1 || s.x>B || s.y<1 || s.y>A)
		return 1;
	return 0;
}

int mian()
{
	int i,j,T,t,a,b,n,m,f;
	char c[5];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&A,&B,&n,&m);
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%s",&a,&b,c);
			s[i].x=a;s[i].y=b;
			vis[a][b]=i;
			if(c[0]=='E')
				s[i].dir=3;
			else if(c[0]=='W')
				s[i].dir=2;
			else if(c[0]=='N')
				s[i].dir=0;
			else s[i].dir=0;
		}
		f=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%s%d",&a,c,&b);
			if(f)
				continue;
			for(j=0;j<b;j++)
			{
				if(c[0]=='L')
				{
					if((t=L(s[a],a))){
						printf("Robot %d crashes into robot %d\n",a,t);
						f=1;break;
					}
				}
				else if(c[0]=='R')
				{
					if((t=R(s[a],a))){
						printf("Robot %d crashes into robot %d\n",a,t);
						f=1;break;
					}
				}
				else {
					if((t=F(s[a],a))){
						printf("Robot %d crashes into robot %d\n",a,t);
						f=1;break;
					}
				}
				if(check(s[a]))
				{
					printf("Robot %d crashes into the wall\n",a);
				}
			}
		}
	}
	return 0;
}



