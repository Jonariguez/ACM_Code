/****************
*PID:hdu4565
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
LL MOD;

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
    LL i,a,b,n,m;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&m)!=EOF){
        Mat trans;
        LL temp=m;
        trans.mat[1][1]=2*a%temp;trans.mat[1][2]=(b-a*a)%temp;
        trans.mat[2][1]=1%temp;trans.mat[2][2]=0;
        MOD=temp;
        Mat res=quick_Pow(trans,n-1);
        LL ans=res.mat[1][1]*2*a%m+res.mat[1][2]*2%m;
        ans%=m;
        if(ans<0)
            ans+=m;
        printf("%I64d\n",ans);
    }
    return 0;
}


