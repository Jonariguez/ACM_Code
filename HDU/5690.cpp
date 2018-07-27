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
Ll quick_pow(Ll a,LL b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
//bool vis[100000007];

int x,k,c;

struct Mat{
    int mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<5;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int K=1;K<=3;K++){
                res.mat[i][j]+=(a.mat[i][K]*b.mat[K][j])%k;
                res.mat[i][j]%=k;
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
    int i,j,n,T,kcase=1;
    sc(T);
    while(T--){
        LL m;
        scanf("%d%I64d%d%d",&x,&m,&k,&c);
        printf("Case #%d:\n",kcase++);
        int d1=x%k;
        int d2=(x*10+x)%k;
        if(m==1){
            if(d1==c)
            puts("Yes");
            else puts("No");
            continue;
        }
        if(m==2){
            if(d2==c)
                puts("Yes");
            else puts("No");
            continue;
        }
        Mat ori;
        ori.mat[1][1]=10%k;ori.mat[1][3]=x%k;
        ori.mat[2][2]=10%k;ori.mat[2][3]=x%k;
        ori.mat[3][3]=1%k;
        Mat res=Matrix_pow(ori,m-2);
        int ans=res.mat[1][1]*d2%k+res.mat[1][2]*d1%k+res.mat[1][3]%k;
        ans%=k;
        if(k==1){
            puts("Yes");continue;
        }
        if(ans==c)
            puts("Yes");
        else puts("No");
    }
    return 0;
}


