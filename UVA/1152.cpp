/*
ÖÐÍ¾ÏàÓö·¨
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=4500;
int a[maxn],b[maxn],c[maxn],d[maxn],ab[maxn*maxn],cd[maxn*maxn];

int main()
{
    int T,j,n;
    ll i,res,tot1,tot2;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        tot1=tot2=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                ab[tot1++]=a[i]+b[j];
                cd[tot2++]=c[i]+d[j];
            }
        res=0;
        sort(cd,cd+tot2);
        for(i=0;i<tot1;i++){
            ll t=(upper_bound(cd,cd+tot2,-ab[i])-cd)-(lower_bound(cd,cd+tot2,-ab[i])-cd);
            res+=t;
        }
        printf("%lld\n",res);
        if(T)
            printf("\n");
    }
    return 0;
}
