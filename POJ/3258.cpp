#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

ll l,n,m;

const int maxn=50000+10;
ll a[maxn];

bool C(ll x){
	ll last=0,i,cnt=0;
	for(i=1;i<=n+1;i++){
		if(a[i]-a[last]<=x) cnt++;
		else last=i;
	}
	return cnt<=m;
}

int main()
{
	int i;
	while(scanf("%I64d%I64d%I64d",&l,&n,&m)!=EOF){
		for(i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		a[0]=0;
		a[n+1]=l;
		sort(a,a+n+2);
		ll L=0,R=l;
		while(R-L>1){
			ll m=(L+R)/2;
			if(C(m))
				L=m;
			else
				R=m;
		}
		printf("%I64d\n",R);
	}
	return 0;
}