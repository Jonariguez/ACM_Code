/****************
*ID:poj3233
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40;
int m,n;

typedef struct pp{
    int M[maxn][maxn];
}Matrix;

Matrix Add(Matrix a,Matrix b){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a.M[i][j]=(a.M[i][j]+b.M[i][j])%m;
    return a;
}

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

Matrix cal(Matrix a,int k){
    if(k==1) return a;
    Matrix temp=cal(a,k/2);       //·ÖÖÎ
    Matrix temp2=Matrix_pow(a,(k+1)/2);
    if(k&1)
        return Add(Add(temp,temp2),Multi(temp2,temp));
    else
        return Add(temp,Multi(temp2,temp));
}

int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        Matrix a;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a.M[i][j]);
        Matrix res=cal(a,k);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                printf("%d%c",res.M[i][j],j==n-1?'\n':' ');
        }
    }
    return 0;
}
