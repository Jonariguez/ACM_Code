/****************
*PID:bz1013
*Auth:Jonariguez
*****************
高斯消元
设三维的两个点(a1,b1,c1),(a2,b2,c2),圆心为(x,y,z)到两点的距离相等推出：
2(a2-a1)x+2(b2-b1)y+2(c2-c1)z = a2^2-a1^2+b2^2-b1^2+c2^2-c1^2
一共n个方程，用后n个方程分别减去第一个方程得到n个方程，解方程即可。
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=20;
const int MOD=1e9+7;

double a[maxn][maxn];
double A[maxn][maxn];
double res[maxn];

void gauss(int n){
    int i,j,k;
    for(i=1;i<=n;i++){
        int t=i;
        for(j=i+1;j<=n;j++)
            if(fabs(A[t][i])<fabs(A[j][i]))
                t=j;
        if(t!=i)
            for(j=i;j<=n+1;j++)
                swap(A[i][j],A[t][j]);
        for(j=i+1;j<=n;j++){
            double x=A[j][i]/A[i][i];
            for(k=i;k<=n+1;k++)
                A[j][k]-=A[i][k]*x;
        }
    }
    for(i=n;i>=1;i--){
        res[i]=A[i][n+1];
        for(j=n;j>i;j--)
            res[i]-=res[j]*A[i][j];
        res[i]/=A[i][i];
    }
    for(i=1;i<=n;i++)
        printf("%.3f%c",res[i]," \n"[i==n]);
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            A[i][j]+=2*(a[i][j]-a[0][j]);
            A[i][n+1]+=a[i][j]*a[i][j]-a[0][j]*a[0][j];
        }
    }
    gauss(n);
    return 0;
}

