#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
#define max(a,b) (a)>(b)?(a):(b)

bool isp[1000002];
void get()
{
	int i,j;
	for(i=0;i*i<=1000000;i++)
	{
		if(!isp[i])
			for(j=i*2;j<=1000000;j+=i)
				isp[j]=1;
	}
}

int main()
{
	int i,a,d,n,cnt;
	isp[0]=isp[1]=1;
	get();
	while(scanf("%d%d%d",&a,&d,&n))
	{
		if(a==0 && d==0 && n==0)
			break;
		cnt=0;
		for(i=a;;i+=d)
		{
			if(!isp[i])
				cnt++;
			if(cnt==n)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}
		
