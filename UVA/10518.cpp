/****************
*PID:uva10518
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
int B;

struct Mat{
    int mat[10][10];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=3;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%B;
                res.mat[i][j]%=B;
            }
        }
    }
    return res;
}

Mat Matrix_pow(Mat a,LL n){
    Mat res;
    res.EMat();
    while(n){
        if(n&1)
            res=Multi(res,a);
        n/=2;
        a=Multi(a,a);
    }
    return res;
}

int main()
{
    int i,j,kcase=1;
    LL n;
    while(scanf("%lld%d",&n,&B)!=EOF){
        if(n==0 && B==0) break;
        Mat trs;
        trs.mat[1][1]=1%B;trs.mat[1][2]=1%B;trs.mat[1][3]=1%B;
        trs.mat[2][1]=1%B;trs.mat[2][2]=0;trs.mat[2][3]=0;
        trs.mat[3][1]=0;trs.mat[3][2]=0;trs.mat[3][3]=1%B;
        int ans=0;
        if(n==0 || n==1)
            ans=1;
        else {
            Mat res=Matrix_pow(trs,n-1);
            ans=res.mat[1][1]+res.mat[1][2]+res.mat[1][3];
        }
        ans%=B;
       // ans=ans%10;
        printf("Case %d: %lld %d %d\n",kcase++,n,B,ans);
    }
    return 0;
}


