/****************
*PID:hdu5667
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
//Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
LL MOD;

struct Mat{
    LL mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=3;i++) mat[i][i]=1;
    }
};

Mat multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                if(res.mat[i][j]>=MOD)
                    res.mat[i][j]-=MOD;
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
            res=multi(res,a);
        b/=2;
        a=multi(a,a);
    }
    return res;
}

LL quick_pow(LL a,LL b){
    LL res=(LL)1%MOD;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int main()
{
    int i,j,T;
    LL a,b,c,n;
    sc(T);
    while(T--){
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&MOD);
        if(n==1){
            printf("%I64d\n",(LL)1%MOD);continue;
        }
        if(n==2){
            printf("%I64d\n",quick_pow(a,b));continue;
        }
        if(a%MOD==0){
            puts("0");continue; //Trick!Trick!!Trick!!!
        }
        MOD--;
        Mat trans;
        trans.mat[1][1]=c%MOD;trans.mat[1][2]=1%MOD;trans.mat[1][3]=b%MOD;
        trans.mat[2][1]=1%MOD;trans.mat[2][2]=0;trans.mat[2][3]=0;
        trans.mat[3][1]=0;trans.mat[3][2]=0;trans.mat[3][3]=1%MOD;
        Mat res=quick_Pow(trans,n-2);
        LL f1=0,f2=b%MOD;
        LL ans=res.mat[1][1]*f2%MOD+res.mat[1][2]*f1%MOD+res.mat[1][3];
        ans%=MOD;
        if(ans<0) ans+=MOD;
        MOD++;
        printf("%I64d\n",quick_pow(a,ans));
    }
    return 0;
}






