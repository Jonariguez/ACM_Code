#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
#define INF 1e10

ll a[1000005];
int n,c;

int C(ll k)
{
	ll i,sum=0,t;
	for(i=0;i<n;i++)
	{
		t=a[i];
		while(i<n && a[i]-t<k)
			i++;
		sum++;
		i--;
	}
	return sum>=c;
}

int main()
{
	int i,j;
	ll l=0,r=INF,m;
	scanf("%d%d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	sort(a,a+n);
	while(l<r)
	{
		m=(l+r)/2;
	//	printf("r=%I64d\n",m);
	//	printf("l=%I64d r=%I64d\n",l,r);
		if(C(m))
			l=m+1;
		else
			r=m;
	}
	printf("%I64d\n",r-1);
	return 0;
}
