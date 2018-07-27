/****************
*PID:hdu5674
*Auth:Jonariguez
*****************
πŸ∑ΩÃ‚Ω‚£∫
http://bestcoder.hdu.edu.cn/
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
typedef long long Ll;
//Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const LL MOD=1000000007;

struct Mat{
    LL mat[3][3];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        mat[1][1]=mat[2][2]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat c;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                c.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                c.mat[i][j]%=MOD;
            }
        }
    }
    return c;
}

Mat quick_Pow(Mat a,LL n){
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

LL multi(LL a,LL b,LL M){
    if(a==0 || b==0) return 0;
    LL res=0;
    while(b){
        if(b&1)
            res=(res+a)%M;
        b/=2;
        a=(a+a)%M;
    }
    return res;
}

LL quick_pow(LL a,LL b,LL M){
    if(a==0) return 0;
    LL res=1;
    while(b){
        if(b&1)
            res=multi(res,a,M);
        b/=2;
        a=multi(a,a,M);
    }
    return res;
}

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        LL a,b,x,y;
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
        LL temp=quick_pow(x,y,MOD*MOD-1);
        if(temp<0) temp+=(MOD-1);
        if(temp==0){
            printf("2\n");continue;
        }
        Mat trans;
        trans.mat[1][1]=(2*a)%MOD;trans.mat[1][2]=(b-a*a)%MOD;
        trans.mat[2][1]=1;trans.mat[2][2]=0;
        Mat res=quick_Pow(trans,temp-1);
        LL ans=(res.mat[1][1]*2%MOD*a%MOD+res.mat[1][2]*2%MOD)%MOD;
        if(ans<0) ans+=MOD;
        printf("%I64d\n",ans%MOD);
    }
    return 0;
}



