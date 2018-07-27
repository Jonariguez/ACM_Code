/****************
*PID:
*Auth:Jonariguez
*****************
每到一天，就将这太那的c[i]加入set，然后取c最大的一天先飞
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

const int maxn=600000+10;
const int MOD=1e9+7;

int c[maxn],ans[maxn];
struct node{
    int v,id;
    bool operator < (const node &r) const {
        if(v==r.v)
            return id<r.id;
        return v<r.v;
    }
};

set<node> s;

int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    s.clear();
    LL sum=0,res=0;
    for(i=1;i<=k;i++){
        s.insert((node){c[i],i});
        res+=sum;
        sum+=c[i];
    }
    for(i=k+1;i<=n;i++){
        s.insert((node){c[i],i});
        res+=sum;
        sum+=c[i];
        ans[(*s.rbegin()).id]=i;
        sum-=(*s.rbegin()).v;
        s.erase(*s.rbegin());
    }
    for(i=n+1;i<=n+k;i++){
        ans[(*s.rbegin()).id]=i;
        res+=sum;
        sum-=(*s.rbegin()).v;
        s.erase(*s.rbegin());
    }
    printf("%I64d\n",res);
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}


