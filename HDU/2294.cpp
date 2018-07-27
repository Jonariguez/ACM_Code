/****************
*PID:hdu2294
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

const int maxn=33;
const LL mod=1234567891;
LL N;

typedef struct Mat{
    LL mat[maxn][maxn];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void Unit(){
        for(int i=0;i<33;i++) mat[i][i]=1;
    }
}Mat;

Mat Multi(Mat a,Mat b){
    Mat res;
    res.Init();
    LL i,j,k;
    for(i=0;i<=N;i++){
        for(j=0;j<=N;j++){
            for(k=0;k<=N;k++){
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                if(res.mat[i][j]>=mod)
                    res.mat[i][j]%=mod;
            }
        }
    }
    return res;
}

Mat quick_pow(Mat a,LL b){
    Mat res;
    res.Init();
    res.Unit();
    while(b){
        if(b&1) res=Multi(res,a);
        b/=2;
        a=Multi(a,a);
    }
    return res;
}

Mat ori,base,res;

void Init(){
    LL i,j,k;
    ori.Init();
    ori.mat[0][0]=N%mod;        //³õÊ¼»¯Îªk
    base.Init();
    base.mat[0][0]=1;
    for(i=1;i<N;i++){
        base.mat[i][i]=i+1;
        base.mat[i-1][i]=N-i;
    }
    base.mat[N-1][N]=base.mat[N][N]=1;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        LL n,k;
        scanf("%lld%lld",&n,&k);
        N=k;
        Init();
        res=Multi(ori,quick_pow(base,n));
      //  res=quick_pow(base,n);
        printf("%lld\n",res.mat[0][k]%mod);
    }
    return 0;
}
