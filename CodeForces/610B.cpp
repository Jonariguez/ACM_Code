/****************
*PID:610b div2
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

const int maxn=200000+10;
LL a[maxn];

int main()
{
    LL i,j,n,res;
    while(scanf("%I64d",&n)!=EOF){
        scanf("%I64d",&a[1]);
        LL b=a[1],cnt=0;
        for(i=2;i<=n;i++){
            scanf("%I64d",&a[i]);
            if(a[i]<b){
                b=a[i];
            }
        }
        a[n+1]=b;
        LL len=0;
        LL now=0;
        for(i=1;i<=n+1;i++){
            if(b==a[i]){
                if(len<=i-now-1){
                    len=i-now-1;
                }
                now=i;
                cnt++;
            }
        }
        cnt--;
        if(cnt==1){
            for(i=1;i<=n;i++)
                if(a[i]==b) break;
            res=n-i;
            res+=n*b;
            res+=(i-1);
            printf("%I64d\n",res);
            continue;
        }
        i=1;j=n;
        while(i<=n && b!=a[i]) i++;
        while(j>=1 && b!=a[j]) j--;
        len=max(len,n-j+i-1);
        res=len+n*b;
        printf("%I64d\n",res);
    }
    return 0;
}
