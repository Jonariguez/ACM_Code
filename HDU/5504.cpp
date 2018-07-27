/****************
*PID:hdu5504
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100;
LL a[maxn];

int main()
{
    int i,j,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1){
            scanf("%lld",&a[0]);
            printf("%lld\n",a[0]);
            continue;
        }
        LL sum=1;
        int cnt=0,cnt0=0,cntz=0;
        LL t=1;
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(a[i]==0){
                cnt0++;
            }
            else {
                sum*=a[i];
                if(a[i]<0){
                    cnt++;
                    if(t==1 || t<a[i]) t=a[i];
                }else cntz++;
            }
        }
     //   printf("t=%lld\nsum=%lld\n",t,sum);
        if(cnt0==n)
            printf("0\n");
        else if(cnt0){
            if(cnt&1 && (cntz || cnt>1))
                printf("%lld\n",max(0LL,sum/t));
            else printf("%lld\n",max(0LL,sum));
        }else {
            if(cnt&1 && (cntz || cnt>1))
                printf("%lld\n",sum/t);
            else printf("%lld\n",sum);
        }
    }
    return 0;
}
