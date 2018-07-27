/****************
*PID:hdu4686
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
const LL MOD=1e9+7;

struct Mat{
    LL mat[10][10];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=5;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=5;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat quick_Pow(Mat a,LL b){
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
    LL i,j,A0,AX,AY,B0,BX,BY,n;
    while(scanf("%I64d",&n)!=EOF){
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&A0,&AX,&AY,&B0,&BX,&BY);
        if(n==0){
            puts("0");continue;
        }
        Mat trans;
        trans.mat[1][1]=AX%MOD;trans.mat[1][5]=AY%MOD;
        trans.mat[2][2]=BX%MOD;trans.mat[2][5]=BY%MOD;
        trans.mat[3][1]=AX%MOD*BY%MOD;trans.mat[3][2]=AY%MOD*BX%MOD;
        trans.mat[3][3]=AX%MOD*BX%MOD;trans.mat[3][5]=AY%MOD*BY%MOD;
        trans.mat[4][1]=AX%MOD*BY%MOD;trans.mat[4][2]=AY%MOD*BX%MOD;
        trans.mat[4][3]=AX%MOD*BX%MOD;trans.mat[4][4]=1;trans.mat[4][5]=AY%MOD*BY%MOD;
        trans.mat[5][5]=1;
        Mat res=quick_Pow(trans,n-1);
        LL ans=res.mat[4][1]*A0%MOD+res.mat[4][2]*B0%MOD+res.mat[4][3]*A0%MOD*B0%MOD+res.mat[4][4]*A0%MOD*B0%MOD+res.mat[4][5];
        ans%=MOD;
        if(ans<0)
            ans+=MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}



