#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef __int64 ll;

const int maxn=50000+10;
int n;
struct pp
{
	ll W,S;
}s[maxn];

int cmp(const pp &x,const pp &y){
	return x.S+x.W<y.S+y.W;
}

ll max(ll x,ll y){
	if(x>y) return x;
	return y;
}


int main()
{
	ll i;
	while(scanf("%I64d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%I64d%I64d",&s[i].W,&s[i].S);
		}
		sort(s,s+n,cmp);
		ll res=-s[0].S,sum=0;
		for(i=0;i<n;i++){
			res=max(res,sum-s[i].S);
			sum+=s[i].W;
		}
		printf("%I64d\n",res);
	}
	return 0;
}

