/****************
*PID:hdu4433
*Auth:Jonariguez
*****************
dp[i][j][k]:前i位ok，第i+1位向上转动了j次，第i+2位向上转动k次的min
答案：dp[n][0][0]
决策分为两种：①向上转，②向下转。
第i-1位的状态dp[i][j][k],向dp[i+1][][]转移，则第i位应该ok，那么因为状态
dp[i][j][k]处理i-1位时，把第i位(即i-1的下一位i-1+1=i)向上转动了j次，则此时
就把a[i]变成了a[i]+j,根据决策①向上转到b[i]，则应该转cnt=(b[i]-(a[i]+j)+20)%10次。
因为第i位转动cnt次，那么第i+1位转动的次数p应该<=cnt,同理第i+2位的转动次数q<=p,
则去枚举p和q，枚举p时，即i+1位时，因为处理dp[i][j][k]时，i-1+2=i+1位是向上转动了
k次，所以再向上转动p次时，那么新状态应该(k+p)%10次。  q则无影响。
决策②同理。
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
const int INF=1e9;
char str[maxn],str2[maxn];
int a[maxn],b[maxn],dp[maxn][10][10];

int main()
{
    int i,j,k,n;
    while(scanf("%s%s",str,str2)!=EOF){
        n=strlen(str);
        for(i=0;i<n;i++){
            a[i]=str[i]-'0';
            b[i]=str2[i]-'0';
        }
        for(i=0;i<=n;i++)
            for(j=0;j<10;j++)
                for(k=0;k<10;k++) dp[i][j][k]=INF;
        dp[0][0][0]=0;
        for(i=0;i<n;i++){
            for(j=0;j<10;j++){
                for(k=0;k<10;k++){
                    if(dp[i][j][k]==INF) continue;
                    int cnt=(b[i]-(a[i]+j)+20)%10;  //向下一个位i推时，由于处理上位i-1时，i位加了j次，故有a[i]+j
                    for(int p=0;p<=cnt;p++){
                        for(int q=0;q<=p;q++){
                            dp[i+1][(k+p)%10][q]=min(dp[i+1][(k+p)%10][q],dp[i][j][k]+cnt);
                        }
                    }
                    cnt=(10-cnt)%10;
                    for(int p=0;p<=cnt;p++){
                        for(int q=0;q<=p;q++){
                            dp[i+1][(k-p+10)%10][(10-q)%10]=min(dp[i+1][(k-p+10)%10][(10-q)%10],dp[i][j][k]+cnt);
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n][0][0]);
    }
    return 0;
}




