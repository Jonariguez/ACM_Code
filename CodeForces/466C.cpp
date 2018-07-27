/****************
*PID:466c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500000+10;
map<LL,LL> mp;
LL a[maxn];

int main()
{
    LL i,j,sum,m,n;
    while(scanf("%I64d",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        if(sum%3){
            puts("0");continue;
        }
        sum/=3;
        mp.clear();
        LL one=0,two=0,thr=0,res=0;
        LL now=0;
        for(i=1;i<=n;i++){
            now+=a[i];
            if(i!=n && now==sum*2){
                res+=mp[sum];
            }
            mp[now]++;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
