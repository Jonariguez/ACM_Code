/****************
*PID:uva11551
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
const int MOD=1000;
int n;

struct Mat{
    int mat[52][52];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=n;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat Matrix_pow(Mat a,int n){
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
    int i,j,T,r,a[55];
    sc(T);
    while(T--){
        scanf("%d%d",&n,&r);
        for(i=1;i<=n;i++){
            sc(a[i]);
            a[i]%=MOD;
        }
        Mat trs;
        for(i=1;i<=n;i++){
            int x,y;
            sc(y);
            while(y--){
                sc(x);
                x++;
                trs.mat[i][x]=1;
            }
        }
        Mat res=Matrix_pow(trs,r);
        for(i=1;i<=n;i++){
            int ans=0;
            for(j=1;j<=n;j++)
                ans=(ans+res.mat[i][j]*a[j])%MOD;
            printf("%d%c",ans," \n"[i==n]);
        }
    }
    return 0;
}



