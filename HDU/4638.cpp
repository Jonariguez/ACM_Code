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

int vis[maxn],a[maxn],unit;

struct node{
    int l,r,id;
}s[maxn];

int cmp(const node &x,const node &y){
    if(x.l/unit==y.l/unit)
        return x.r<y.r;
    return x.l/unit<y.l/unit;
}

int res[maxn];

void work(int m){
    int now=0,i,L=1,R=0;
    memset(res,0,sizeof(res));
    memset(vis,0,sizeof(vis));
    for(i=1;i<=m;i++){
        while(R<s[i].r){
            R++;
            vis[a[R]]=1;
            if(vis[a[R]-1] && vis[a[R]+1])
                now--;
            else if(vis[a[R]-1]==0 && vis[a[R]+1]==0)
                now++;
        }
        while(R>s[i].r){
            vis[a[R]]=0;
            if(vis[a[R]-1] && vis[a[R]+1])
                now++;
            else if(vis[a[R]-1]==0 && vis[a[R]+1]==0)
                now--;
            R--;
        }
        while(L<s[i].l){
            vis[a[L]]=0;
            if(vis[a[L]-1] && vis[a[L]+1])
                now++;
            else if(vis[a[L]-1]==0 && vis[a[L]+1]==0)
                now--;
            L++;
        }
        while(L>s[i].l){
            L--;
            vis[a[L]]=1;
            if(vis[a[L]-1]==0 && vis[a[L]+1]==0)
                now++;
            else if(vis[a[L]-1]==1 && vis[a[L]+1]==1)
                now--;
        }
        res[s[i].id]=now;
    }
}

int main()
{
    int i,j,T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++){
            scanf("%d%d",&s[i].l,&s[i].r);
            s[i].id=i;
        }
        unit=(int)sqrt(n);
        sort(s+1,s+m+1,cmp);
        work(m);
        for(i=1;i<=m;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}


