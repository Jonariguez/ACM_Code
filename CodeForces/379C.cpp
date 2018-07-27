/****************
*PID:379c bye2013
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

const int maxn=300000+10;
int res[maxn];

struct pp{
    int v,id;
}s[maxn];

int cmp(pp a,pp b){
    return a.v<b.v;
}

int main()
{
    int i,j,n;
    while(sc(n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&s[i].v);
            s[i].id=i;
        }
        sort(s+1,s+n+1,cmp);
        int now=s[1].v;
        res[s[1].id]=now;
        for(i=2;i<=n;i++){
            now++;
            res[s[i].id]=max(now,s[i].v);
            now=max(now,s[i].v);
        }
        for(i=1;i<=n;i++)
            printf("%d%c",res[i]," \n"[i==n]);
    }
    return 0;
}


