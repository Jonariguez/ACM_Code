/****************
*PID:hdu4906
*Auth:Jonariguez
*****************
状压dp
dp[i] = j;其中i转换为二进制,1表示可以求得该位,0表示不可求得。j 表示 种数。
比如说:dp[5] = 3. 因为5的二进制是1 0 1.所以和为1的串有3个.和为3的串也有3个。
和为 2 的串不可求，因为5转换为二进制后，第二位是0.
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=21;
const int MOD=1e9+7;
LL dp[2][1<<maxn];

int main()
{
    int i,j,n,m,L,k,T;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&k,&L);
        memset(dp,0,sizeof(dp));
        int ALL=(1<<k)-1;
        int pre=0,now=1;
        int mx=min(L,k);
        dp[pre][0]=1;
        for(i=0;i<n;i++){
            memset(dp[now],0,sizeof(dp[now]));
            for(int S=0;S<=ALL;S++){
                if(dp[pre][S]==0) continue;
                int cnt=1;  //如果L<=k,ai只要取0时才会对状态转移没有影响
                if(L>k)
                    cnt+=L-k;   //如果L>k,则ai除了取0对状态转移没有影响，取[k+1,L]也没有影响
                dp[now][S]=(dp[now][S]+dp[pre][S]*cnt%MOD)%MOD;
                for(j=1;j<=mx;j++){ //ai去[1,min(L,k)]里的数j对状态的转移
                    //S| 说明S的状态里的数都会保存
                    //|(S<<j) 说明是S里面的数都加上j得到的新数集合
                    //|(1<<(j-1)) 既然加上j了，说明肯定少不了j这个数了
                    //&ALL 由于有(S<<j)，那么加上j之后，对于那些大于k的数自然就丢弃了，所以通过&ALL来保证st的
                    //集合在[0,1<<k)内。
                    int st=((S|(S<<j)|(1<<(j-1)))&ALL);
                    dp[now][st]=(dp[now][st]+dp[pre][S])%MOD;
                }
            }
            swap(now,pre);
        }
        LL res=0;
        for(i=1;i<=ALL;i++)
            if(i&(1<<(k-1))){
                res+=dp[pre][i];
                res%=MOD;
            }
        if(res<0)
            res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}




