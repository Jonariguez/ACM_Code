#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;
#define min(a,b) (a)<(b)?(a):(b)

ll a[100003];

int main()
{
	ll i,j,k,t,s,n,T;
	ll res,sum;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		res=n;sum=0;t=0;
		for(s=0;s<n;s++)
		{
			while(t<n && sum<k)
				sum+=a[t++];
			if(sum>=k)
			{
				res=min(res,t-s);
				sum-=a[s];
			}
			else
				break;
		}
		if(res==n)
			printf("0\n");
		else
		printf("%I64d\n",res);
	}
	return 0;
}
