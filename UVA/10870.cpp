/****************
*PID:uva10870
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=20;
typedef long long Matrix[maxn][maxn];
LL a[maxn];
LL d,n,m,MOD;

void matrix_mul(Matrix A,Matrix B,Matrix C){
    int i,j,k;
    Matrix res;
    memset(res,0,sizeof(res));
    for(i=0;i<d;i++)
        for(j=0;j<d;j++){
            for(k=0;k<d;k++){
                res[i][j]=(res[i][j]+A[i][k]*B[k][j])%MOD;
            }
        }
    memcpy(C,res,sizeof(res));
}

void matrix_pow(Matrix A,int n,Matrix C){
    Matrix res;
    int i;
    memset(res,0,sizeof(res));
    for(i=0;i<d;i++) res[i][i]=1;
    while(n){
        if(n&1)
            matrix_mul(res,A,res);
        n/=2;
        matrix_mul(A,A,A);
    }
    memcpy(C,res,sizeof(res));
}


int main()
{
    LL i,j,k;
    while(scanf("%lld%lld%lld",&d,&n,&MOD)){
        if(d==0 && n==0 && MOD==0) break;
        Matrix e,ans;
        memset(e,0,sizeof(e));
        for(i=d-1;i>=0;i--){
            LL x;
            scanf("%lld",&x);
            e[d-1][i]=x%MOD;
            if(i)
                e[i-1][i]=1LL;
        }
        for(i=0;i<d;i++){
            scanf("%lld",&a[i]);
            a[i]%=MOD;
        }
        if(n<=d){
            printf("%lld\n",a[n-1]);continue;
        }
        matrix_pow(e,n-d,ans);
        LL res=0;
        for(i=0;i<d;i++)
            res=(res+a[i]*ans[d-1][i])%MOD;
        if(res<0) res+=MOD;
        printf("%lld\n",res%MOD);
    }
    return 0;
}
