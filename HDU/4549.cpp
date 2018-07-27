/****************
*PID:hdu4549
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
LL quick_pow(LL a,LL b,LL MOD){a%=MOD;LL res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
LL MOD=1000000007;

struct Mat{
    LL mat[4][4];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        mat[1][1]=mat[2][2]=1;
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
    LL a,b,n;
    Mat trans;
    trans.mat[1][1]=1;trans.mat[1][2]=1;
    trans.mat[2][1]=1;trans.mat[2][2]=0;
    while(scanf("%I64d%I64d%I64d",&a,&b,&n)!=EOF){
        if(n==0)
            printf("%I64d\n",a);
        else if(n==1)
            printf("%I64d\n",b);
        else if(n==2)
            printf("%I64d\n",a*b%MOD);
        else {
            MOD--;
            Mat res=quick_Pow(trans,n-1);
            LL ta=res.mat[2][1],tb=res.mat[1][1];
            MOD++;
            printf("%I64d\n",quick_pow(a,ta,MOD)*quick_pow(b,tb,MOD)%MOD);
        }
    }
    return 0;
}




