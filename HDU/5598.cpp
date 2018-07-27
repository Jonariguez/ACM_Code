/****************
*PID:hdu5598
*Auth:Jonariguez
*****************
一个数字和其它若干个不同的数字xor的结果肯定是互不相同的.
g xor x=t xor y
通过移项，就变成了g xor t=x xor y
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MOD=1000000007;

LL ans,x,l,r;

void dfs(LL cur,LL A,LL B){
    if(A>r || B>r) return ;
    if(A+(1LL<<(cur+1))-1<l || B+(1LL<<(cur+1))-1<l) return ;
    if(A>=l && A+(1LL<<(cur+1))-1<=r && B>=l && B+(1LL<<(cur+1))-1<=r){
        ans+=1LL<<(cur+1);ans%=MOD;return ;
    }
    if(cur<0) return ;
    if((x&(1LL<<cur))==0){
        dfs(cur-1,A,B);
        dfs(cur-1,(A|(1LL<<cur)),(B|(1LL<<cur)));
    }else {
        dfs(cur-1,(A|(1LL<<cur)),B);
        dfs(cur-1,A,(B|(1LL<<cur)));
    }
}

int main()
{
    LL i,j,n,G,t;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&l,&r,&G,&t);
        LL res=((r-l+1)*2)%MOD;
        ans=0;
        x=G^t;
        dfs(61,0LL,0LL);
        res-=ans;
        res=(res%MOD+MOD)%MOD;
        printf("%lld\n",res);
    }
    return 0;
}

