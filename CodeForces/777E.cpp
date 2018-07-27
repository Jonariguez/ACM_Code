/****************
*PID:777e
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

struct node{
    int a,b,h;
}s[maxn];

int cmp(const node &x,const node &y){
    if(x.b==y.b)
        return x.a>y.a;
    return x.b>y.b;
}

vector<int> vec;

typedef struct Segment{
    LL sum[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=0;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int p,LL v,int k,int l,int r){
        if(l==r){
            sum[k]=max(sum[k],v);return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,lson);
        else update(p,v,rson);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        vec.clear();
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].h);
            vec.push_back(s[i].a);
            vec.push_back(s[i].b);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        sort(s+1,s+n+1,cmp);
        for(i=1;i<=n;i++){
            s[i].a=(upper_bound(vec.begin(),vec.end(),s[i].a)-vec.begin());
            s[i].b=(upper_bound(vec.begin(),vec.end(),s[i].b)-vec.begin());
        }
        int N=vec.size();
        tree.build(1,1,N);
        LL res=0,dp;
        for(i=1;i<=n;i++){
            dp=tree.ask(1,s[i].b-1,1,1,N)+s[i].h;
            res=max(res,dp);
            tree.update(s[i].a,dp,1,1,N);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
