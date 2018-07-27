/****************
*PID:hdu5524
*Auth:Jonariguez
*****************
the analysis of the function dfs check 5524a
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n,a[100000],cnt,height;

void cal(LL x){
    for(LL i=1;i<=x;i++)
        a[cnt++]=(1LL<<i)-1;
}

void dfs(LL u,LL d,LL sum){
    a[cnt++]=sum;
    if(u==1) return ;
    LL x;
    if(u&1)
        x=height-d+1;
    else x=height-d;
    cal(x);
    dfs(u/2,d-1,sum+(1LL<<x));
}

int main()
{
    int i,j;
    while(scanf("%lld",&n)!=EOF){
        LL m=n-1;
        LL cur=2;
        height=0;
        while(m>0){
            m-=cur;
            cur*=2;
            height++;
        }
        height++;
        cnt=0;
        dfs(n,height,1LL);
        a[cnt++]=n;
        sort(a,a+cnt);
        m=unique(a,a+cnt)-a;
        printf("%I64d\n",m);
    }
    return 0;
}
