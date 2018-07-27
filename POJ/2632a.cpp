#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 500

int vis[112][112];

struct robot
{
	int x,y;
	int dir;	//0ио 1об 2вС 3ср
}s[111];

int A,B;

void L(int a)
{
	if(s[a].dir==0) s[a].dir=2;
	else if(s[a].dir==1) s[a].dir=3;
	else if(s[a].dir==2) s[a].dir=1;
	else if(s[a].dir==3) s[a].dir=0;
}

void R(int a)
{
	if(s[a].dir==0) s[a].dir=3;
	else if(s[a].dir==1) s[a].dir=2;
	else if(s[a].dir==2) s[a].dir=0;
	else if(s[a].dir==3) s[a].dir=1;
}

int check(robot s)
{
	if(s.x<1 || s.x>B || s.y<1 || s.y>A)
		return 1;
	return 0;
}

int F(int a)
{
	vis[s[a].x][s[a].y]=0;
	if(s[a].dir==0) s[a].x--;
	else if(s[a].dir==1) s[a].x++;
	else if(s[a].dir==2) s[a].y--;
	else if(s[a].dir==3) s[a].y++;
	if(check(s[a]))
		return N;
	if(vis[s[a].x][s[a].y])
		return vis[s[a].x][s[a].y];
	vis[s[a].x][s[a].y]=a;
	return 0;
}


int main()
{
	int i,j,T,t,a,b,n,m,f;
	char c[5];
	int from,to;
	int k1,k2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&A,&B,&n,&m);
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%s",&a,&b,c);
			s[i].x=B+1-b;s[i].y=a;
			vis[B+1-b][a]=i;
			if(c[0]=='E')
				s[i].dir=3;
			else if(c[0]=='W')
				s[i].dir=2;
			else if(c[0]=='N')
				s[i].dir=0;
			else s[i].dir=1;
		}
		f=0;to=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%s%d",&a,c,&b);
			if(f)
				continue;
			if(c[0]=='L')
				for(j=0;j<b;j++)
					L(a);
			else if(c[0]=='R')
				for(j=0;j<b;j++)
					R(a);
			else
			for(j=0;j<b;j++)
			{
				t=F(a);
		//		printf("t=%d\n",t);
		//		for(k1=1;k1<=B;k1++)
		//		{
		//			for(k2=1;k2<=A;k2++)
		//			printf("%d ",vis[k1][k2]);
		//			printf("\n");
		//		}
				if(t==N){
					f=1;from=a;to=N;break;
				}
				else if(t){
					f=1;from=a;to=t;break;
				}
			}
		}
		if(f)
		{
			printf("Robot %d crashes into ",from);
			if(to==N)
				printf("the wall\n");
			else
				printf("robot %d\n",to);
		}
		else
			printf("OK\n");
	}
	return 0;
}



