/****************
*PID:hdu4990
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
int MOD;

struct Mat{
    LL mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=2;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
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
    int i,j,n;
    while(scanf("%d%d",&n,&MOD)!=EOF){
        Mat odd;
        odd.mat[1][1]=2%MOD;odd.mat[1][2]=0;
        odd.mat[2][1]=1%MOD;odd.mat[2][2]=1%MOD;
        Mat even;
        even.mat[1][1]=2%MOD;even.mat[1][2]=0;
        even.mat[2][1]=0;even.mat[2][2]=1%MOD;
        Mat trans;
        trans.mat[1][1]=4%MOD;trans.mat[1][2]=0;
        trans.mat[2][1]=2%MOD;trans.mat[2][2]=1%MOD;
        Mat res=quick_Pow(trans,n/2);
        LL ans=0;
        if(n&1)
            res=Multi(res,odd);
        ans=res.mat[2][1];
        printf("%I64d\n",ans%MOD);
    }
    return 0;
}



