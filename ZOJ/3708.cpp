/****************
*PID:zoj3708
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

const int maxn=500+10;
int a[maxn][maxn];
int x[maxn],y[maxn];

int main()
{
    int i,n,T,m;
    sc(T);
    while(T--){
        sc(n);sc(m);
        memset(a,0,sizeof(a));
        for(i=1;i<=m;i++) sc(x[i]);
        for(i=1;i<=m;i++) sc(y[i]);
        int cnt=0;
        for(i=1;i<=m;i++){
            if(a[x[i]][y[i]]) continue;
            cnt++;
            a[x[i]][y[i]]=a[y[i]][x[i]]=1;
        }
        printf("%.3f\n",(double)cnt/n);
    }
    return 0;
}


