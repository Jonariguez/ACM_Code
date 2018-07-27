/****************
*PID:hdu3292
*Auth:Jonariguez
*****************
佩尔方程:
X^2 - N*Y^2 = 1
X是完全平方数时无解
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int m=8191;
int n=2;

typedef struct pp{
    int M[3][3];
}Matrix;

Matrix Multi(Matrix a,Matrix b){
    int i,j,k;
    Matrix c;
    memset(c.M,0,sizeof(c.M));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                c.M[i][j]+=(a.M[i][k]*b.M[k][j])%m;
                c.M[i][j]%=m;
            }
        }
    }
    return c;
}

Matrix Matrix_pow(Matrix a,int k){
    Matrix e;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            e.M[i][j]=(j==i);
    while(k){
        if(k&1)
            e=Multi(e,a);
        k/=2;
        a=Multi(a,a);
    }
    return e;
}

int main()
{
    int i,j,N,k;
    while(scanf("%d%d",&N,&k)!=EOF){
        int t=sqrt(N+0.0);
        if(t*t==N){
            printf("No answers can meet such conditions\n");
            continue;
        }
        int y=1,x;
        while(true){
            x=(long long)sqrt((double)N*y*y+1.0);
            if(x*x-N*y*y==1)
                break;
            y++;
        }
        Matrix a;
        a.M[0][0]=x%m;
        a.M[0][1]=N*y%m;
        a.M[1][0]=y%m;
        a.M[1][1]=x%m;
        Matrix r=Matrix_pow(a,k-1);
        int res=(r.M[0][0]*x+r.M[0][1]*y)%m;
        printf("%d\n",res);
    }
    return 0;
}
