#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
typedef __int64 ll;

ll x[100010];
int main()
{
	ll i,j,n,k,t,ans;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%I64d",&x[i]);
		sort(x,x+n);
		ans=0;
		for(i=0;x[i]+k<=x[n-1];i++){
			t=lower_bound(x,x+n,x[i]+k)-x-i;
			ans+=t;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
