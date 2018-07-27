/****************
*PID:hdu1757
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

const int maxn=1000000+5;
LL mod;

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
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            for(k=1;k<=10;k++){
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
    for(i=1;i<=10;i++)
        ori.mat[1][i]=10-i;
    base.Init();
    for(i=1;i<10;i++)
        base.mat[i][i+1]=1;
    while(scanf("%lld%lld",&k,&mod)!=EOF){
        for(i=1;i<=10;i++)
            scanf("%lld",&base.mat[i][1]);
        if(k<10){
            printf("%lld\n",k);continue;
        }
        res=Multi(ori,quick_pow(base,k-9));
        printf("%lld\n",res.mat[1][1]%mod);
    }
    return 0;
}
