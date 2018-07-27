/****************
*PID:51nod1242
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+9;

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
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                res.mat[i][j]%=MOD;
            }
        }
    }
    return res;
}

Mat POW(Mat a,LL n){
    Mat res;
    res.Init();
    res.EMat();
    while(n){
        if(n&1) res=multi(res,a);
        n/=2;
        a=multi(a,a);
    }
    return res;
}

int main()
{
    LL n;
    scanf("%I64d",&n);
    Mat ori;
    ori.mat[1][1]=1;ori.mat[1][2]=ori.mat[2][1]=1;ori.mat[2][2]=0;
    Mat res=POW(ori,n-1);
    LL ans=res.mat[1][1];
    printf("%I64d\n",ans);
    return 0;
}


