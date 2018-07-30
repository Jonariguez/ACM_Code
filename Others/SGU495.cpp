/****************
*PID:SGU495
*Auth:Jonariguez
*****************
��Ϊÿ��������õ��������ô�����õ�1�����
�������������Կɵã��õ������������������ÿ��
�õ�����ĸ���֮�͡�
dp[i]:��i�����õ�����ĸ���
������i�����õ�����ĸ��ʣ������i-1����û���õ�
������i���õ�����ĸ��ʺ͵�i-1�����õ������
������һ���ģ���P(�͵�i-1����һ��)*P(��i����û�õ�);
�����i-1�����õ��ˣ����i���õ�����ĸ��ʻ��
��i-1�����õ�����ĸ���С1/n����
P(��i-1�����õ��ĸ���)*(P(��i-1�����õ��ĸ���-)-1/n)
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

const int maxn=100000+10;
double dp[maxn]; //dp[i]:��i���õ�����ĸ���

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(i=2;i<=m;i++)
            dp[i]=(1-dp[i-1])*dp[i-1]+dp[i-1]*(dp[i-1]-1.0/n);
        double res=0;
        for(i=1;i<=m;i++)
            res+=dp[i];
        printf("%.10f\n",res);
    }
    return 0;
}


