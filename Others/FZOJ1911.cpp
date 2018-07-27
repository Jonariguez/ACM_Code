/****************
*PID:foj1911
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
int M;

struct Mat{
    int mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=1;i<=2;i++)
            mat[i][i]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                res.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%M;
                res.mat[i][j]%=M;
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

int res[220][220];

int main()
{
    int i,j,n,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&M);
        Mat trs;
        trs.mat[1][1]=1%M;trs.mat[1][2]=1%M;
        trs.mat[2][1]=1%M;
        Mat temp=Matrix_pow(trs,n); //S[n]=f(n+2)-1
        int ans=temp.mat[1][1]+temp.mat[1][2]-1;
     //   printf("ans=%d\n",ans);
        ans%=M;
        if(ans<0) ans+=M;
        if(ans<2 || ans&1)
            printf("Case %d: No\n",kcase++);
        else {
            printf("Case %d: Yes\n",kcase++);
            memset(res,0,sizeof(res));
            int l=-ans+1,r=ans;
            for(i=1;i<=ans;i+=2){
                for(j=1;j<=abs(l);j++)
                    res[j][i]=-1;
                l++;
                int now=r;
                j=ans;
                while(now--) res[j--][i+1]=1;
                r--;
            }
            for(i=1;i<=ans;i++){
                for(j=1;j<=ans;j++)
                    printf("%d%c",res[i][j]," \n"[j==ans]);
            }
        }
    }
    return 0;
}


