/****************
*PID:zoj3712
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

const int maxn=100000+10;

int a[maxn],p[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        LL res1=0,res2=0;
        int x,y,z;
        sc(x);sc(y);sc(z);
        a[3]=x;a[2]=y;a[1]=z;
        p[3]=300;p[2]=100;p[1]=50;
        int now=1;
        res2=0;
        for(i=1;i<=3;i++){
            while(a[i]--){
                res2+=(LL)now*p[i];
                now+=2;
            }
        }
        res1=0;
        a[1]=x;a[2]=y;a[3]=z;
        p[1]=300;p[2]=100;p[3]=50;
        now=1;
        for(i=1;i<=3;i++){
            while(a[i]--){
                res1+=(LL)now*p[i];
                now+=2;
            }
        }
        printf("%lld %lld\n",res1,res2);
    }
    return 0;
}



