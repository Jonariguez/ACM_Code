/****************
*PID:448c div2
*Auth:Jonariguez
*****************
·ÖÖÎ
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int a[maxn];

int solve(int l,int r){
	if(l>r) return 0;
	if(l==r) return 1;
	if(l==r-1){
		return min(2,max(a[l],a[r]));
	}//puts("??");
	int i,res=2e9,index=0;
	for(i=l;i<=r;i++){
		if(a[i]<res){
			res=a[i];index=i;
		}
	}
	if(res>=r-l+1)
		return r-l+1;
	for(i=l;i<=r;i++) a[i]-=res;
	int sum=0,last=l,j;
	for(i=l;i<=r;){
        j=i;
        while(j<=r && a[j]==0) j++;
        if(j>r) break;
        last=j;
        while(j<=r && a[j]) j++;
        sum+=solve(last,j-1);
        i=j;
	}
	return min(sum+res,r-l+1);
}

int main()
{
	int i,j,n,m;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",solve(1,n));
	}
	return 0;
}
