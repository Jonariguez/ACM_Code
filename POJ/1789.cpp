#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char d[2003][9];

struct pp
{
	int a,b;
	int v;
}s[4000002];

int cmp(const pp &x,const pp &y)
{
	return x.v<y.v;
}

int count(char s1[],char s2[])
{
	int cnt=0,i;
	for(i=0;i<7;i++)
		if(s1[i]!=s2[i])
			cnt++;
	return cnt;
}

int f[2002];

void init(int n)
{
	int i;
	for(i=0;i<=n;i++)
		f[i]=i;
}

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}

int Union(int x,int y)
{
	if((x=find(x))==(y=find(y)))
		return 0;
	f[y]=x;
	return 1;
}


int main()
{
	int i,j,k,n,cnt,aa,bb,res;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			scanf("%s",d[i]);
		init(n);
		k=0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				s[k].a=i;s[k].b=j;
				s[k++].v=count(d[i],d[j]);
			}
		}
		sort(s,s+k,cmp);
		res=0;cnt=0;
		for(i=0;i<k;i++)
		{
	//		printf("f[%d]=%d,f[%d]=%d\n",s[i].a,find(s[i].a),s[i].b,find(s[i].b));
			if(Union(s[i].a,s[i].b))
			{
				res+=s[i].v;
				cnt++;
			}
			if(cnt==n-1)
				break;
		}
	//	printf("cnt=%d\n",cnt);
		if(cnt==n-1)
			printf("The highest possible quality is 1/%d.\n",res);
	}
	return 0;
}

