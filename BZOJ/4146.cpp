#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=2000000+10;

int a[maxn],vis[maxn],res[maxn];

int main()
{
    int i,j,n;
    ll sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    sum=0;
    for(i=1;i<=2000000;i++){
        for(j=i;j<=2000000;j+=i)
            res[i]+=vis[j];
    }
    for(i=1;i<=n;i++)
        sum+=res[a[i]]-1;
    printf("%lld\n",sum);
    return 0;
}
