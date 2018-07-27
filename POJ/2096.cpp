/****************
*PID:poj2096
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

const int maxn=1000+10;
double E[maxn][maxn];

int main()
{
    int i,j,n,s;
    scanf("%d%d",&n,&s);
    memset(E,0,sizeof(E));
    E[n][s]=0;
    for(i=n;i>=0;i--){
        for(j=s;j>=0;j--){
            double sum=0;
            if(j<s)
                sum+=(double)i*(s-j)*E[i][j+1];
            if(i<n)
                sum+=(double)(n-i)*j*E[i+1][j];
            if(j<s && i<n)
                sum+=E[i+1][j+1]*(n-i)*(s-j);
            sum+=n*s;
            if(i==n && j==s) continue;
            sum/=(n*s-i*j);
            E[i][j]=sum;
        }
    }
    printf("%.4f\n",E[0][0]);
    return 0;
}



