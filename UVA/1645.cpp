/***************
*ID:uva1645
*Auth:Jonariguez
****************
递推：
每个结点的每个子树都是相同的。所以n结果为n-1的所有约数的结果加起来。
上面留作一个是根
f[n]=sigma(d|n-1){f[(n-1)/d]}
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD=1e9+7;
const int maxn=1000+5;
int f[maxn];

void pre_solve(){
    int i,j;
    memset(f,0,sizeof(f));
    f[1]=1;
    for(i=1;i<=1000;i++)
        for(int n=i;n<1000;n+=i)
            f[n+1]=(f[n+1]+f[i])%MOD;
}

int main()
{
    int i,n,kcase=1;
    pre_solve();
    while(scanf("%d",&n)!=EOF){
        printf("Case %d: %d\n",kcase++,f[n]);
    }
    return 0;
}
