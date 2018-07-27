/****************
*PID:385e div2
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
LL N;

struct Mat{
    LL mat[10][10];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<10;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%N;
                res.mat[i][j]%=N;
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
    int i,j,sx,sy,dx,dy;
    LL t;
    while(scanf("%I64d%d%d%d%d%I64d",&N,&sx,&sy,&dx,&dy,&t)!=EOF){
        Mat ori;
        ori.mat[1][1]=(LL)sx-1;
        ori.mat[2][1]=(LL)sy-1;
        ori.mat[3][1]=(LL)dx;
        ori.mat[4][1]=(LL)dy;
        ori.mat[5][1]=0;
        ori.mat[6][1]=1;
        Mat trs;
        trs.mat[1][1]=trs.mat[1][6]=2%N;trs.mat[1][2]=trs.mat[1][3]=trs.mat[1][5]=1%N;
        trs.mat[2][1]=trs.mat[2][4]=trs.mat[2][5]=1%N;trs.mat[2][2]=trs.mat[2][6]=2%N;
        trs.mat[3][1]=trs.mat[3][2]=trs.mat[3][3]=trs.mat[3][5]=1%N;trs.mat[3][6]=2%N;
        trs.mat[4][1]=trs.mat[4][2]=trs.mat[4][4]=trs.mat[4][5]=1%N;trs.mat[4][6]=2%N;
        trs.mat[5][5]=trs.mat[5][6]=1%N;
        trs.mat[6][6]=1%N;
        Mat res=Matrix_pow(trs,t);
        LL ansx=0,ansy=0;
        for(i=1;i<=6;i++){
            ansx+=res.mat[1][i]*ori.mat[i][1]%N;
            ansx%=N;
            ansy+=res.mat[2][i]*ori.mat[i][1]%N;
            ansy%=N;
        }
        if(ansx<0) ansx+=N;
        if(ansy<0) ansy+=N;
        printf("%I64d %I64d\n",ansx+1,ansy+1);
    }
    return 0;
}


