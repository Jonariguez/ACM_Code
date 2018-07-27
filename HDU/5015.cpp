/****************
*PID:hdu5015
*Auth:Jonariguez
*****************
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
const LL MOD=10000007;
int n;

struct Mat{
    LL mat[15][15];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=12;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=n+2;i++){
        for(int j=1;j<=n+2;j++){
            for(int k=1;k<=n+2;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                //if(res.mat[i][j]>=MOD)
                    res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat quick_Pow(Mat a,int b){
    Mat res;
    res.EMat();
    while(b){
        if(b&1)
            res=Multi(res,a);
        b/=2;
        a=Multi(a,a);
    }
    return res;
}

int main()
{
    int i,j,m;
    int a[15];
    a[1]=23;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=2;i<=n+1;i++)
            scanf("%d",&a[i]);
        a[n+2]=3;
        Mat trans;
        for(i=1;i<=n+2;i++){
            if(i<n+2)
                trans.mat[i][1]=10;
            trans.mat[i][n+2]=1;
            if(i==n+2) break;
            for(j=2;j<=i;j++)
                trans.mat[i][j]=1;
        }
        Mat res=quick_Pow(trans,m);
        LL ans=0;
        for(i=1;i<=n+2;i++){
            ans+=res.mat[n+1][i]*a[i];
            ans%=MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

