#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cmp(int a,int b)
{
	return a>b;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int i,k,n,sum,res,a[110],b[110],f;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n==3)
		{
			printf("%d\n",a[2]-a[0]);
			continue;
		}
		for(i=0;i<n-1;i++)
			b[i]=a[i+1]-a[i];
		sort(b,b+n-1,cmp);
		res=3000;f=0;
		for(i=1;i<n-1;i++)
		{
			sum=a[i+1]-a[i]+a[i]-a[i-1];
			if(sum<b[0])
			{
				f=1;
				break;
			}
			else
				res=min(res,sum);
		}
		if(f)
			printf("%d\n",b[0]);
		else
			printf("%d\n",res);
	}
	return 0;
}