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
const int INF=1e9;
int a[maxn],dp[maxn];
priority_queue<int,vector<int>,greater<int> > que1,que2[maxn];

typedef struct Segment{
    int sum[maxn*4];
    void pushUp(int k){
        sum[k]=min(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=INF;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=min(sum[k],v);return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,lson);
        else update(p,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=INF;
        if(a<=m)
            res=min(res,ask(a,b,lson));
        if(b>m)
            res=min(res,ask(a,b,rson));
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sc(a[i]);
    }
    tree.build(1,1,n);
    printf("0");
    int now=0;
    tree.update(a[1],a[1]+1,1,1,n);
    now=-1;
    for(i=2;i<=n;i++){
        int res=now+i;
        res=min(res,tree.ask(i,n,1,1,n)-i);
        printf(" %d",res);
        tree.update(a[i],res+1+a[i],1,1,n);
        now=min(now,res-i);
    }
    puts("");
    return 0;
}

