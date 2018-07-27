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

const int maxn=100000+10;
const int MOD=1e9+7;

LL a[maxn];

struct node{
    LL l,r;
}s[maxn];

int cmp(const node &x,const node &y){
    if(x.l==y.l)
        return x.r<y.r;
    return x.l<y.l;
}

int main()
{
    int i,j,n,T;
    sc(T);
    while(T--){
        LL L,R;
        scanf("%d%lld%lld",&n,&L,&R);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        int m=0,yes=1;
        for(i=2;i<=n;i++){
            if(a[i]-a[i-1]+1>R) continue;
            if(a[i]+a[i-1]-1<L) continue;
            if(a[i]-a[i-1]+1<=L && a[i]+a[i-1]-1>=R){
                yes=0;break;
            }
            m++;
            s[m].l=a[i]-a[i-1]+1;
            if(s[m].l<L)
                s[m].l=L;
            s[m].r=a[i]+a[i-1]-1;
            if(s[m].r>R)
                s[m].r=R;
        }
        if(yes==0){
            puts("0");continue;
        }
        sort(s+1,s+m+1,cmp);
        LL res=0,now=L-1;
        for(i=1;i<=m;i++){
            if(s[i].l>now+1)
                res+=s[i].l-now-1;
            now=max(s[i].r,now);
        }
    /*    for(i=1;i<=m;){
            j=i;
            while(j<=m){
                if(s[j].l>now+1) break;
                now=max(now,s[j].r);
                j++;
            }
            if(j>m) break;
            res+=s[j].l-now-1;
            now=max(now,s[j].r);
            i=j;
        }*/
        if(R>now)
            res+=R-now;
        printf("%lld\n",res);
    }
    return 0;
}

