/****************
*PID:poj3661
*Auth:Jonariguez
*****************
ע����Ŀ˵Ҫ��Ϣ����Ҫ��Ϣ��ƣ�Ͷ�Ϊ0�˲����ټ����ܡ�һ��ʼû����
dp[i][j]:��i����ʱ��ƣ�Ͷ�Ϊjʱ���ܵ���Զ���롣
dp[i][j]��������״̬ת�ƹ����������ߣ�
�ٵ�i����Ϣ��ƣ�Ͷ�Ϊ0����dp[i][0]=max(dp[i-1][0],dp[i-k][k]),k>0����Ϊ��i-k��ʱ�ܵ�ƣ�Ͷ�Ϊk��maxdist��
�ڵ�i���ܲ�����dp[i][j]=max(dp[i][j],dp[i-1][j-1]+D[i])
�𰸣�dp[n][0]
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

const int maxn=10000+10;
const int maxm=500+5;
int n,m,d[maxn],dp[maxn][maxm];

int main()
{
    int i,j;
    sc(n);sc(m);
    for(i=1;i<=n;i++) sc(d[i]);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+d[i]);
            if(j<i)
                dp[i][0]=max(dp[i][0],dp[i-j][j]);
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}



