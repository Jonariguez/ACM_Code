/****************
*PID:
*Auth:Jonariguez
*****************
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

const int maxn=2000000+10;
const int MOD=1e9+7;

LL a[maxn],b[maxn];

int main()
{
    LL i,j,n,ts,tf,t;
    scanf("%I64d%I64d%I64d",&ts,&tf,&t);
    scanf("%I64d",&n);
    for(i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    if(n==0){
        printf("%I64d\n",ts);return 0;
    }
    if(a[1]>ts){
        printf("%I64d\n",ts);
        return 0;
    }
    LL now=ts,rest=ts-a[1]+1,res=a[1]-1;
    for(i=1;i<=n;i++){
        if(now>=tf) break;
        if(now<a[i]){
            printf("%I64d\n",now);return 0;
        }
        if(rest>now-(a[i]-1) && now+t<=tf){
            rest=now-(a[i]-1);
            res=a[i]-1;
        }
        now+=t;
    }
    if(now+t<=tf)
        printf("%I64d\n",now);
    else
        printf("%I64d\n",res);
    return 0;
}



