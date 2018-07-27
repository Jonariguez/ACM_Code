#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef __int64 ll;
const int maxn=100000+10;
ll a[maxn],k,n;

bool C(ll x){
	ll i,cnt=0;
	for(i=0;i<n;i++)
		cnt+=(a+n)-lower_bound(a+i,a+n,x+a[i]);		//����lower_bound��ô�a+i��ʼ����Ȼ��TLE
	return cnt<=k;
}

int main()
{
	ll i,b;
	while(scanf("%I64d",&n)!=EOF){
		ll l=0,r=-1;
		for(i=0;i<n;i++){
			scanf("%I64d",&a[i]);
			if(r<a[i]) r=a[i];			//����rҪ��ʼ��Ϊ������������������������������1000000000����Ȼ��TLE 
		}
		k=((n-1)*n/2)/2;
		sort(a,a+n);
		while(r-l>1){
			ll m=(l+r)/2;
			if(C(m))
				r=m;
			else 
				l=m;
		}
		printf("%I64d\n",l);
	}
	return 0;
}