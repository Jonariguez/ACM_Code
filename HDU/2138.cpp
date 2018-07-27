#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100000+10;
int a[maxn];

int main()
{
	int i,k,T,kcase=1,n,q,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("Case %d:\n",kcase++);
		while(q--){
			scanf("%d%d",&x,&y);
			printf("%d\n",upper_bound(a,a+n,y)-lower_bound(a,a+n,x));
		}
	}
	return 0;
}