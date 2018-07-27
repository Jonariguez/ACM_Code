#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;
#define eps 1e-9

ll a[10020];

int main()
{
	ll i,k,ans;
	int n;
	a[0]=0;
	for(i=1;i<=10000;i++)
	{
		k=(ll)floor((sqrt(8.0*i+1)-1)/2-eps)+1;
		a[i]=a[i-1]+k;
	}
	while(scanf("%d",&n),n)
	{
		printf("%d %lld\n",n,a[n]);
	}
	return 0;
}
