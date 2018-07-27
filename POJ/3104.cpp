/*
二分求下界
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100000+10;
ll a[maxn];
ll n,k;

bool C(ll x){
	ll i,cnt=0;
	for(i=0;i<n;i++)
		if(a[i]>x)
			cnt+=(a[i]-x+k-2)/(k-1);
	return cnt<=x;
}
	

int main()
{
	ll i,j,max;
	while(scanf("%d",&n)!=EOF){
		max=-1;
		for(i=0;i<n;i++){
			scanf("%I64d",&a[i]);
			if(max<a[i])
				max=a[i];
		}
		scanf("%I64d",&k);
		if(k==1){
			printf("%I64d\n",max);
			continue;
		}
		ll l=0,r=1000000000;
		while(r-l>1){
			int m=(l+r)/2;
			if(C(m))
				r=m;
			else
				l=m;
		}
		printf("%I64d\n",r);
	}
	return 0;
}
