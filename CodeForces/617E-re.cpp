/****************
*PID:617e div2
*Auth:Jonariguez
*****************
其实莫队区间为:[l-1,r],且！i！=j
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
int a[maxn],cnt[1<<21],sum[maxn],n,m,k;
int unit;

struct Com{
    int l,r,id;
}s[maxn];

int cmp(const Com &x,const Com &y){
    if(x.l/unit==y.l/unit)
        return x.r<y.r;
    return x.l/unit<y.l/unit;
}

LL res[maxn];

void solve(){
    int L=1,R=0;
    memset(cnt,0,sizeof(cnt));
    LL now=0;
    for(int i=1;i<=m;i++){
        while(R<s[i].r){
            R++;
            int v=k^sum[R];
            now+=cnt[v];
            cnt[sum[R]]++;
        }
        while(R>s[i].r){
            int v=k^sum[R];
            cnt[sum[R]]--;  //因为位置不能相同，所以要先当前位置的减了
            now-=cnt[v];
            R--;
        }
        while(L>=s[i].l){
            L--;
            int v=k^sum[L];
            now+=cnt[v];
            cnt[sum[L]]++;
        }
        while(L<s[i].l-1){
            int v=k^sum[L];
            cnt[sum[L]]--;
            now-=cnt[v];
            L++;
        }
        res[s[i].id]=now;
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;i++){
            sc(a[i]);
            sum[i]=(sum[i-1]^a[i]);
        }
        unit=(int)sqrt(n+0.5);
        for(i=1;i<=m;i++){
            scanf("%d%d",&s[i].l,&s[i].r);
            s[i].id=i;
        }
        sort(s+1,s+m+1,cmp);
        solve();
        for(i=1;i<=m;i++)
            printf("%I64d\n",res[i]);
    }
    return 0;
}



