/****************
*PID:392c div1
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

const int maxn=100;
const LL MOD=1e9+7;
int N;
LL fact[maxn],C[maxn][maxn];

void table(){
    int i,j;
    for(i=0;i<=41;i++){
        for(j=0;j<=41;j++){
            if(j==i || j==0)
                C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
}

struct Mat{
    LL mat[maxn][maxn];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=N;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                res.mat[i][j]%=MOD;
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

LL quick_pow(LL a,int b){
    LL res=1;
    while(b){
        if(b&1)
            res=res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}

int main()
{
    int i,j,k;
    table();
    fact[0]=1;
    for(i=1;i<=41;i++)
        fact[i]=fact[i-1]*2%MOD;
    LL n;
    while(scanf("%I64d%d",&n,&k)!=EOF){
        if(n==1){
            printf("1\n");continue;
        }
        if(n==2){
            printf("%I64d\n",(1+quick_pow((LL)2,k+1))%MOD);continue;
        }
        Mat ori;
        for(i=0;i<=k;i++)
            ori.mat[i+1][1]=2*quick_pow((LL)2,i)%MOD;
        for(;i<=k*2+1;i++)
            ori.mat[i+1][1]=1;
        ori.mat[k*2+3][1]=(1+2*quick_pow((LL)2,k))%MOD;
        Mat trs;
        for(i=1;i<=k+1;i++){
            for(j=0;j<i;j++)
                trs.mat[i][j+1]=C[i-1][j];
            for(j=k+1;j<k+i+1;j++)
                trs.mat[i][j+1]=C[i-1][j-k-1]*fact[i+k-j]%MOD;
        }
        j=1;
        for(i=k+2;i<=k*2+2;i++)
            trs.mat[i][j++]=1;
        for(i=1;i<=k+1;i++)
            trs.mat[2*k+3][i]=C[k][i-1];
        for(i=k+2;i<=k*2+2;i++)
            trs.mat[2*k+3][i]=C[k][i-k-2]*fact[k*2-i+2];
        N=k*2+3;
        trs.mat[N][N]=1;
        Mat res=Matrix_pow(trs,n-2);
     /*   for(i=1;i<=N;i++){
            for(j=1;j<=N;j++)
                printf("%d ",trs.mat[i][j]);
            puts("");
        }*/
        LL ans=0;
        for(i=1;i<=k*2+3;i++){
          //  printf("ori=%I64d ",ori.mat[i][1]);
            ans+=res.mat[k*2+3][i]*ori.mat[i][1]%MOD;
            ans%=MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

