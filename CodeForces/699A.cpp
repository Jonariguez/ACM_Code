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

const int maxn=200000+10;
const int MOD=1e9+7;

char str[maxn];
struct pp{
    int a,f;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.a<y.a;
}

int main()
{
    int i,j,n,m;
    while(sc(n)!=EOF){
        scanf("%s",str+1);
        for(i=1;i<=n;i++){
            sc(s[i].a);
            if(str[i]=='L')
                s[i].f=0;
            else s[i].f=1;
        }
        sort(s+1,s+n+1,cmp);
        int res=1e9+4;
        for(i=1;i<n;i++)
            if(s[i].f==1 && s[i+1].f==0)
                res=min(res,(s[i+1].a-s[i].a)/2);
        if(res==1e9+4)
            puts("-1");
        else printf("%d\n",res);
    }
    return 0;
}


