/****************
*PID:hdu2604
*Auth:Jonariguez
*****************
http://www.cnblogs.com/jackge/archive/2013/06/20/3147074.html
f(n)=f(n-1)+f(n-3)+f(n-4)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+5;
LL mod;

typedef struct Mat{
    LL mat[10][10];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void Unit(){
        for(int i=0;i<10;i++) mat[i][i]=1;
    }
}Mat;

Mat Multi(Mat a,Mat b){
    Mat res;
    res.Init();
    LL i,j,k;
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            for(k=1;k<=4;k++){
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
    LL i,j,k;
    ori.Init();
    ori.mat[1][1]=9;ori.mat[1][2]=6;
    ori.mat[1][3]=4;ori.mat[1][4]=2;
    base.Init();
    base.mat[1][1]=1;base.mat[1][2]=1;
    base.mat[2][3]=1;base.mat[3][1]=1;
    base.mat[3][4]=1;base.mat[4][1]=1;
    while(scanf("%lld%lld",&k,&mod)!=EOF){
        if(k<=4){
            printf("%lld\n",ori.mat[1][5-k]%mod);continue;
        }
        if(mod==1){
            printf("0\n");continue;
        }
        res=Multi(ori,quick_pow(base,k-4));
        printf("%lld\n",res.mat[1][1]%mod);
    }
    return 0;
}

