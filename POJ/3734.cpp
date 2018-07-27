/****************
*PID:poj3734
*Auth:Jonariguez
*****************
递推+矩阵快速幂
递推所求的同时，并递推其他情况以辅助。
从左向右进行，设前i个方块中，
红绿都染偶数个的方案数为ai
红绿只有一个染偶数个的方案为bi
红绿都染奇数个的方案数为ci。
则
a(i+1)=2*ai+bi
b(i+1)=2*ai+2*bi+2*ci
c(i+1)=bi+2*ci
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int mod=10007;

struct Mat{
    int mat[5][5];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    Mat operator * (const Mat &r) const {
        Mat res;
        memset(res.mat,0,sizeof(res.mat));
        int i,j,k;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    res.mat[i][j]+=(mat[i][k]*r.mat[k][j])%mod;
                    res.mat[i][j]%=mod;
                }
            }
        }
        return res;
    }
}e,A;

Mat Pow(Mat x,int n){
    Mat res=e;
    while(n){
        if(n&1) res=res*x;
        n/=2;
        x=x*x;
    }
    return res;
}

int main()
{
    int i,j,T,n;
    e.mat[0][0]=e.mat[1][1]=e.mat[2][2]=1;
    A.mat[0][0]=2;A.mat[0][1]=1;A.mat[0][2]=0;
    A.mat[1][0]=2;A.mat[1][1]=2;A.mat[1][2]=2;
    A.mat[2][0]=0;A.mat[2][1]=1;A.mat[2][2]=2;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        Mat res;
        res=Pow(A,n);
        printf("%d\n",res.mat[0][0]);
    }
    return 0;
}
