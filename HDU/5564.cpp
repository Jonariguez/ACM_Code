/****************
*PID:hdu5564
*Auth:Jonariguez
*****************
构造矩阵时用++而不用1，是因为从一个状态到另一个
状态的方案数，是由乘法原理计算的，故要乘上每加一位
数的方式数。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=77;
const LL mod=1e9+7;
LL N;

typedef struct Mat{
    LL mat[maxn][maxn];
    void Init(){
        memset(mat,0,sizeof(mat));
    }
    void Unit(){
        for(int i=0;i<77;i++) mat[i][i]=1;
    }
}Mat;

Mat Multi(Mat a,Mat b){
    Mat res;
    res.Init();
    LL i,j,k;
    for(i=0;i<=70;i++){
        for(j=0;j<=70;j++){
            for(k=0;k<=70;k++){
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

LL State(LL x,LL y){  //余数为x，最后一位为y，压缩成状态
    return x*10+y;
}

void Init(LL k){
    LL i,j;
    ori.Init();
    base.Init();
    for(i=0;i<7;i++){
        for(j=0;j<10;j++){
            for(LL v=0;v<10;v++){
                if(j+v==k) continue;
                base.mat[State(i,j)][State((i*10+v)%7,v)]++;
                LL x=(10*i+v)%7;
                if(x==0)
                    base.mat[State(i,j)][70]++;//当以j结尾，余数为i时，累计能整除7(x==0)的个数。
            }
        }
    }
    base.mat[70][70]=1;
    for(i=1;i<10;i++)   //注意这里初始化是对第一位初始化，故i不能等于0
        ori.mat[0][State(i%7,i)]++;
    ori.mat[0][70]=1;
}

LL solve(LL n){
    if(n==0) return 0;
    if(n==1) return 1;
    res.Init();
    res=Multi(ori,quick_pow(base,n-1));
    return res.mat[0][70]%mod;
}

int main()
{
    LL i,j,n,m,l,r,k;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&l,&r,&k);
        Init(k);
        printf("%I64d\n",(solve(r)-solve(l-1)+mod)%mod);
    }
    return 0;
}
