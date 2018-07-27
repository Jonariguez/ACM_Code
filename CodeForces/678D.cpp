/****************
*PID:
*Auth:Jonariguez
*****************
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

const int maxn=200000+10;
const int MOD=1e9+7;

struct Mat{
    LL mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=4;i++)
            mat[i][i]=1;
    }
};

Mat multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat Pow(Mat a,LL n){
    Mat res;
    res.EMat();
    while(n){
        if(n&1)
            res=multi(res,a);
        n/=2;
        a=multi(a,a);
    }
    return res;
}

int main()
{
    int i,j;
    LL a,b,n,x;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&x)!=EOF){
        Mat ori;
        ori.mat[1][1]=a;ori.mat[1][3]=1;
        ori.mat[2][2]=a;ori.mat[2][3]=1;
        ori.mat[3][3]=1;
        LL g0=x,g1=(a*x%MOD+b)%MOD;
        if(n==0){
            printf("%I64d\n",g0);
        }else if(n==1){
            printf("%I64d\n",g1);
        }else {
            Mat res=Pow(ori,n-1);
            LL ans=0;
            ans=res.mat[1][1]*g1+res.mat[1][2]*g0+res.mat[1][3]*b;
            ans%=MOD;
            if(ans<0)
                ans+=MOD;
            Pfn(ans);
        }
    }
    return 0;
}


