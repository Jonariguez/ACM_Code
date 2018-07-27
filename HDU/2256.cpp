/****************
*PID:hdu2256
*Auth:Jonariguez
*****************
http://www.cnblogs.com/wally/archive/2013/03/01/2939318.html
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+5;
const LL mod=1024;

typedef struct Mat{
    LL mat[12][12];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void Unit(){
        for(int i=0;i<12;i++) mat[i][i]=1;
    }
}Mat;

Mat Multi(Mat a,Mat b){
    Mat res;
    res.Init();
    LL i,j,k;
    for(i=1;i<=2;i++){
        for(j=1;j<=2;j++){
            for(k=1;k<=2;k++){
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

int main()
{
    int i,j,T;
    scanf("%d",&T);
    ori.Init();
    ori.mat[1][1]=5;ori.mat[2][1]=2;
    base.Init();
    base.mat[1][1]=5;base.mat[1][2]=12;
    base.mat[2][1]=2;base.mat[2][2]=5;
    while(T--){
        LL n;
        scanf("%lld",&n);
       // res=Multi(ori,quick_pow(base,n));
        res=quick_pow(base,n);
        printf("%lld\n",(res.mat[1][1]*2-1)%mod);
    }
    return 0;
}
