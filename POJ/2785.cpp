#include <stdio.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

ll sa[16000002],sb[16000002];
ll a[4002],b[4002],c[4002],d[4002];

int main()
{
	ll i,j,k,v,n,t;
	ll res;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d%I64d",&a[i],&b[i],&c[i],&d[i]);
	}
	v=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			sa[v]=a[i]+b[j];
			sb[v++]=c[i]+d[j];
		}
//	sort(sa,sa+v);
	sort(sb,sb+v);
	res=0;
	for(i=0;i<v;i++)
	{
		
		k=0-sa[i];
		t=upper_bound(sb,sb+v,k)-lower_bound(sb,sb+v,k);
		res+=t;
	}
	printf("%I64d\n",res);
	return 0;
}




