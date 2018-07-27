#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 300

int n,m,start;
double v;
int all;


struct pp
{
	int a,b;
	double com,rat;
}s[max];

double dis[110];

int bellman()
{
	memset(dis,0,sizeof(dis));
	dis[start]=v;
	int k,j,i,f;
	for(i=1;i<=n;i++)
	{
		f=0;
		for(j=0;j<all;j++)
		{
			if(dis[s[j].b]<(dis[s[j].a]-s[j].com)*s[j].rat){
				f=1;
				dis[s[j].b]=(dis[s[j].a]-s[j].com)*s[j].rat;
			}
		}
		if(!f)
			break;
	}
	return f;
}



int main()
{
	int i,j,k;
	int t1,t2;
	double t3,t4,t5,t6;
	while(scanf("%d%d%d%lf",&n,&m,&start,&v)!=EOF)
	{
		all=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%lf%lf%lf%lf",&t1,&t2,&t3,&t4,&t5,&t6);
			s[all].a=t1;s[all].b=t2;
			s[all].rat=t3;s[all++].com=t4;
			s[all].a=t2;s[all].b=t1;
			s[all].rat=t5;s[all++].com=t6;
		}
		if(bellman())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
