/****************
*PID:821e
*Auth:Jonariguez
*****************
dp[i][j]表示到达(i,j)的方案数
dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]
很明显当前状态只和i-1状态有关，故考虑有矩阵加速
只需要注意每一阶段的矩阵大小都不一样，分别
为(c[i]+1)阶方针
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=200+10;
const int MOD=1e9+7;

int N;

typedef struct MM{
    LL mat[20][20];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=0;i<=N;i++)
            mat[i][i]=1;
    }
}Mat;

Mat multi(Mat a,Mat b){
    Mat res;
    res.Init();
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=N;k++){
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j]%MOD;
                res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat Pow(Mat a,LL n){
    Mat res;
    res.Init();
    res.EMat();
    while(n){
        if(n&1)
            res=multi(res,a);
        n/=2;
        a=multi(a,a);
    }
    return res;
}

LL a[maxn],b[maxn],dp[20],f[20];
int c[maxn];

int main()
{
    int i,j,n;
    LL k;
    scanf("%d%I64d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%I64d%I64d%d",&a[i],&b[i],&c[i]);
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    a[0]=0;
    for(i=1;i<=n;i++){
        for(j=19;j>c[i];j--) dp[j]=0;   //将这条线之上的状态清掉
        Mat ori;
        ori.Init();
        for(j=0;j<=c[i];j++){
            if(j>0) ori.mat[j-1][j]=1;
            if(j<c[i]) ori.mat[j+1][j]=1;
            ori.mat[j][j]=1;
        }
        N=c[i];
        LL K;
        if(b[i]<k)
            K=b[i]-a[i];
        else K=k-a[i];
        Mat res=Pow(ori,K);
        memset(f,0,sizeof(f));
        for(j=0;j<=c[i];j++){
            for(int q=0;q<=c[i];q++){
                f[j]+=res.mat[q][j]*dp[q]%MOD;
                f[j]%=MOD;
            }
        }
        for(j=0;j<=c[i];j++) dp[j]=f[j];
        if(k<=b[i]) break;
    }
    printf("%I64d\n",dp[0]);
    return 0;
}

