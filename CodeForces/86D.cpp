/****************
*PID:86d div1
*Auth:Jonariguez
*****************
Äª¶Ó
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

const int maxn=200000+10;
int a[maxn],cnt[1000005],n,m,unit;
LL res[maxn];

struct Command{
    int L,R,id;
}s[maxn];

int cmp(const Command &x,const Command &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

void solve(){
    int L=1,R=0,i;
    LL now=0;
    for(i=1;i<=m;i++){
        while(R<s[i].R){
            R++;
            now-=(LL)cnt[a[R]]*cnt[a[R]]*a[R];
            cnt[a[R]]++;
            now+=(LL)cnt[a[R]]*cnt[a[R]]*a[R];
        }
        while(R>s[i].R){
            now-=(LL)cnt[a[R]]*cnt[a[R]]*a[R];
            cnt[a[R]]--;
            now+=(LL)cnt[a[R]]*cnt[a[R]]*a[R];
            R--;
        }
        while(L<s[i].L){
            now-=(LL)cnt[a[L]]*cnt[a[L]]*a[L];
            cnt[a[L]]--;
            now+=(LL)cnt[a[L]]*cnt[a[L]]*a[L];
            L++;
        }
        while(L>s[i].L){
            L--;
            now-=(LL)cnt[a[L]]*cnt[a[L]]*a[L];
            cnt[a[L]]++;
            now+=(LL)cnt[a[L]]*cnt[a[L]]*a[L];
        }
        res[s[i].id]=now;
    }
}







int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++) sc(a[i]);
        memset(cnt,0,sizeof(cnt));
        unit=(int)sqrt(n);
        for(i=1;i<=m;i++){
            scanf("%d%d",&s[i].L,&s[i].R);
            s[i].id=i;
        }
        sort(s+1,s+m+1,cmp);
        solve();
        for(i=1;i<=m;i++)
            Pfn(res[i]);
    }
    return 0;
}



