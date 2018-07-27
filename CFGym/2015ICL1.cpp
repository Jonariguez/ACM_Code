/****************
*PID:A
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

const int maxn=100000+10;
const LL base=1000000;
const LL top=12*base*base;
LL a[maxn];
LL h,m,s,t[maxn],sum[maxn];
int n;


int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d%I64d",&h,&m,&s);
            t[i]=h*base*base+m*base+s;
        }
        sort(t+1,t+n+1);
        t[0]=0;
        sum[1]=0;
        LL now=0;
        for(i=2;i<=n;i++){
            sum[i]=(top-(t[i]-t[1]));
            now+=sum[i];
            sum[i]+=t[i-1]-t[1];
        }
        LL res=now;
        for(i=2;i<=n;i++){
            now-=sum[i];
            now+=(n-1)*(t[i]-t[i-1]);
            res=min(res,now);
        }
        LL cnt;
        printf("%I64d ",(cnt=res/base/base));
        res%=(base*base);
        printf("%I64d ",res/base);
        printf("%I64d\n",res%base);
    }
    return 0;
}


