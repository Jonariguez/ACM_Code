/****************
*PID:621e div2
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

const int maxn=50000+10;
const int MOD=1e9+7;
LL a[maxn],cnt[10],N;

typedef struct Mat{
    LL mat[110][110];
    void Init(){ memset(mat,0,sizeof(mat)); }
    void Unit(){
        for(int i=0;i<=100;i++) mat[i][i]=1;
    }
}Mat;

Mat Multi(Mat a,Mat b){
    Mat res;
    res.Init();
    int i,j,k;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                if(res.mat[i][j]>=MOD) res.mat[i][j]%=MOD;
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
        if(b&1)
            res=Multi(res,a);
        b/=2;
        a=Multi(a,a);
    }
    return res;
}

Mat ori,res;

int main()
{
    LL i,j,n,b,x,k;
    while(scanf("%I64d%I64d%I64d%I64d",&n,&b,&k,&x)!=EOF){
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            cnt[a[i]]++;
        }
        N=x;
        ori.Init();
        for(i=0;i<x;i++){
            for(j=0;j<10;j++){
                ori.mat[i][(i*10+j)%x]+=cnt[j];
            }
        }
        res=quick_pow(ori,b);
        printf("%I64d\n",res.mat[0][k]);
    }
    return 0;
}



