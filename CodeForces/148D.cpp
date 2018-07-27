/****************
*PID:148d div2
*Auth:Jonariguez
*****************
dp[i][j]:现有i只白鼠，j只黑鼠，且公主先捉，公主赢的概率：
1、王妃抓到一只白鼠，则王妃赢了，概率为i/(i+j);
2、王妃抓到一只黑鼠，龙抓到一只白色，则王妃输了，概率为j/(i+j)*i/(i+j-1).(不计入dp[i][j]，因为这是输了啊）
3、王妃抓到一只黑鼠，龙抓到一只黑鼠，跑出来一只黑鼠，则转移到dp[i][j-3]。
概率为j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2);
4、王妃抓到一只黑鼠，龙抓到一只黑鼠，跑出来一只白鼠，则转移到dp[i-1][j-2].
概率为j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2);
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

const int maxn=1000+10;
double dp[maxn][maxn];  //dp[w][b]

int main()
{
    int i,j,w,b;
    while(scanf("%d%d",&w,&b)!=EOF){
        for(i=0;i<=b;i++)
            dp[0][i]=0;
        for(i=1;i<=w;i++)
            dp[i][0]=1;
        for(i=1;i<=w;i++){
            for(j=1;j<=b;j++){
                dp[i][j]=(double)i/(i+j);
                if(j>=3)
                    dp[i][j]+=dp[i][j-3]*j/(j+i)*(j-1)/(i+j-1)*(j-2)/(i+j-2);
                if(j>=2)
                    dp[i][j]+=dp[i-1][j-2]*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2);
            }
        }
        printf("%.10f\n",dp[w][b]);
    }
    return 0;
}



