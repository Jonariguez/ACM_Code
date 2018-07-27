/****************
*PID:hdu4965
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

const int maxn=1000+5;
int N,K;

struct Mat{
    LL mat[10][10];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=10;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=K;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%6;
                res.mat[i][j]%=6;
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

LL A[maxn][8],B[8][maxn],D[maxn][maxn],ans[maxn][maxn];

LL solve(){
    int i,j,k;
     for(i=1;i<=N;i++)
        for(j=1;j<=K;j++)
            scanf("%I64d",&A[i][j]);
    for(i=1;i<=K;i++)
        for(j=1;j<=N;j++)
            scanf("%I64d",&B[i][j]);
    Mat c;
    for(i=1;i<=K;i++){
        for(j=1;j<=K;j++){
            for(k=1;k<=N;k++){
                c.mat[i][j]+=(B[i][k]*A[k][j])%6;
                c.mat[i][j]%=6;
            }
        }
    }
    Mat res=quick_Pow(c,N*N-1);
    memset(ans,0,sizeof(ans));
    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            for(k=1;k<=K;k++){
                ans[i][j]+=(A[i][k]*res.mat[k][j])%6;
                ans[i][j]%=6;
            }
        }
    }
    memset(D,0,sizeof(D));
    LL sum=0;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            for(k=1;k<=K;k++){
                D[i][j]+=(ans[i][k]*B[k][j])%6;
                D[i][j]%=6;
            }
            sum+=D[i][j];
        }
    }
    return sum;
}

int main()
{
    int i,j,k;
    while(scanf("%d%d",&N,&K)){
        if(N==0 && K==0)
            break;
        LL temp=solve();
        printf("%I64d\n",temp);
    }
    return 0;
}





