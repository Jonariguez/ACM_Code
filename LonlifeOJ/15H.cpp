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
int a[maxn];

typedef struct Segment{
    LL maxv[maxn*4],add[maxn*4];
    void pushUp(int k){
        maxv[k]=max(maxv[k*2],maxv[k*2+1]);
    }
    void build(int k,int l,int r){
        add[k]=0;
        if(l==r){
            maxv[k]=(LL)a[l];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void pushDown(int k){
        if(add[k]){
            maxv[k*2]+=add[k];maxv[k*2+1]+=add[k];
            add[k*2]+=add[k];add[k*2+1]+=add[k];
            add[k]=0;
        }
    }
    void Add(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;
            maxv[k]+=v;
            return ;
        }
        int m=(l+r)/2;
        pushDown(k);
        if(a<=m)
            Add(a,b,v,lson);
        if(b>m)
            Add(a,b,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int v,int k,int l,int r){
        if(l==r){
            if(maxv[k]>=v) return l;
            else return -1;
        }
        if(a<=l && r<=b){
            if(maxv[k]<v) return -1;
            else {
                int m=(l+r)/2,res=-1;
                pushDown(k);
                if(a<=m)
                    res=ask(a,b,v,lson);
                if(res<1 && b>m)
                    res=ask(a,b,v,rson);
                if(res<1) res=-1;
                pushUp(k);
                return res;
            }
        }
        pushDown(k);
        int m=(l+r)/2,res=-1;
        if(a<=m)
            res=ask(a,b,v,lson);
        if(res<=0 && b>m)
            res=ask(a,b,v,rson);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        tree.build(1,1,n);
        while(m--){
            int o,l,r,v;
            scanf("%d%d%d%d",&o,&l,&r,&v);
            if(o==1){
              //  tree.ask(l,r,v,1,1,n,res);
                printf("%d\n",tree.ask(l,r,v,1,1,n));
            }else tree.Add(l,r,v,1,1,n);
        }
    }
    return 0;
}

