/****************
*PID:zoj3329
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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

const int maxn=500+50;
double p[maxn],A[maxn],B[maxn];

int main()
{
    int i,j,k,n,k1,k2,k3,a,b,c,d,T;
    sc(T);
    while(T--){
        scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
        memset(p,0,sizeof(p));
        double temp=1.0/k1/k2/k3;
        for(i=1;i<=k1;i++)
            for(j=1;j<=k2;j++)
                for(k=1;k<=k3;k++)
                    if(i!=a || j!=b || k!=c)
                        p[i+j+k]+=temp;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for(i=n;i>=0;i--){
            A[i]=temp;B[i]=1;  //A[i]=temp其实是i转回到0的概率。
            for(j=3;j<=k1+k2+k3;j++){
                A[i]+=p[j]*A[i+j];
                B[i]+=p[j]*B[i+j];
            }
        }
        printf("%.16lf\n",B[0]/(1-A[0]));
    }
    return 0;
}



