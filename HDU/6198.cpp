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
const LL MOD=998244353;

typedef struct MM{
    LL mat[3][3];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        mat[1][1]=mat[2][2]=1;
    }
}Mat;

Mat multi(Mat a,Mat b){
    Mat res;
    res.Init();
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

Mat Pow(Mat a,int n){
    Mat res;
    res.Init();
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
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        n*=2;
        n+=3;
        Mat res;
        res.mat[1][1]=0;res.mat[1][2]=1;
        res.mat[2][1]=1;res.mat[2][2]=1;
        Mat ans=Pow(res,n);
        LL x=ans.mat[1][2];
        x%=MOD;
        x--;
        if(x<0)
            x+=MOD;
        printf("%I64d\n",x);
    }
    return 0;
}

