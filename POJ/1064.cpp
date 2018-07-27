#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
#define INF 1e8
#define eps 1e-9

ll n,k;
double a[10005];

int C(double x)
{
	ll i,res=0;
	for(i=0;i<n;i++)
	{
		res+=(ll)(a[i]/x);
	}
	return res>=k;
}

int main()
{
	ll i,j,sum;
	double l,r,m;
	while(scanf("%I64d%I64d",&n,&k)!=EOF)
	{
		if(n==0 && k==0)
			break;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			sum+=(int)floor(a[i]);
		}
		l=0;r=INF;
		for(i=0;i<100;i++)
		{
			m=(l+r)/2;
		//	printf("m=%.1f\n",m);
			if(C(m))
				l=m;
			else
				r=m;
		}
		if(fabs(l-0.01)<eps)
			printf("0.00\n");
		else
		printf("%.2f\n",floor(r*100)/100);
	}
	return 0;
}
