/****************
*PID:431b div2
*Auth:Jonariguez
*****************
next_permutation ±©Á¦
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

const int maxn=100000+10;
int a[10][10],p[maxn];

int main()
{
    int i,j,n,res;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++) sc(a[i][j]);
    res=0;
    for(i=1;i<=5;i++) p[i]=i;
    do{
        int sum=0;
        for(i=1;i<=5;i++){
            for(j=i;j<=5;j+=2){
                int x=p[j],y=p[j+1];
                sum+=a[x][y]+a[y][x];
            }
        }
        res=max(res,sum);
    }while(next_permutation(p+1,p+6));
    printf("%d\n",res);
    return 0;
}


