/****************
*PID:poj3744
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
int a[15];
double p;

struct Mat{
    double mat[4][4];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        mat[1][1]=mat[2][2]=1.0;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
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

double solve(int len){
    if(len<=0) return 1.0;
    Mat ori;
    ori.mat[1][1]=p;ori.mat[2][1]=1;
    Mat trs;
    trs.mat[1][1]=p;trs.mat[1][2]=1-p;
    trs.mat[2][1]=1;
    Mat res=Matrix_pow(trs,len-1);
    double ans=0;
    ans=res.mat[1][1]*ori.mat[1][1]+res.mat[1][2]*ori.mat[2][1];
    return ans;
}

int main()
{
    int i,j,n;
    while(scanf("%d%lf",&n,&p)!=EOF){
        for(i=1;i<=n;i++)
            sc(a[i]);
        sort(a+1,a+n+1);
        a[0]=0;
        double ans=1.0;
        for(i=1;i<=n;i++){
            int len=a[i]-a[i-1]-1;
            ans*=(1.0-solve(len));
        }
        printf("%.7f\n",ans);
    }
    return 0;
}



