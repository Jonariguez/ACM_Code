/****************
*PID:DQUERY
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

const int maxn=30000+10;
int a[maxn],cnt[1000005],res[200005];
int unit,n,m;

struct Command{
    int L,R,id;
}s[200005];

int cmp(const Command &x,const Command &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

void solve(){
    int L=1,R=0,i,now=0;
    for(i=0;i<m;i++){
        while(R<s[i].R){
            R++;
            if(++cnt[a[R]]==1) now++;
        }
        while(R>s[i].R){
            if(--cnt[a[R]]==0) now--;
            R--;
        }
        while(L<s[i].L){
            if(--cnt[a[L]]==0) now--;
            L++;
        }
        while(L>s[i].L){
            L--;
            if(++cnt[a[L]]==1) now++;
        }
        res[s[i].id]=now;
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sc(a[i]);
    memset(cnt,0,sizeof(cnt));
    sc(m);
    for(i=0;i<m;i++){
        sc(s[i].L);sc(s[i].R);
        s[i].id=i;
    }
    unit=(int)sqrt(n);
    sort(s,s+m,cmp);
    solve();
    for(i=0;i<m;i++)
        pfn(res[i]);
    return 0;
}

