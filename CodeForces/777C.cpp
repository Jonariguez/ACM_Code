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

vector<int> vec[maxn];
int n,m;

int ID(int i,int j){
    return (i-1)*m+j;
}

typedef struct segment{
    int sum[maxn*4];
    void  pushUp(int k){
        sum[k]=min(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=MOD;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=v;return ;
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
        int m=(l+r)/2,res=MOD;
        if(a<=m)
            res=min(res,ask(a,b,lson));
        if(b>m)
            res=min(res,ask(a,b,rson));
        return res;
    }
}Tree;

Tree tree;
int last[maxn];

int main()
{
    int i,j,q;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        vec[i].push_back(0);
        for(j=1;j<=m;j++){
            int x;
            sc(x);
            vec[i].push_back(x);
        }
    }
    int N=n*m;
    tree.build(1,1,N);
    for(i=1;i<=m;i++){
        last[1]=1;
        tree.update(ID(1,i),1,1,1,N);
        for(j=2;j<=n;j++){
            if(vec[j][i]>=vec[j-1][i])
                last[j]=last[j-1];
            else last[j]=j;
            tree.update(ID(j,i),last[j],1,1,N);
        }
    }
    sc(q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int x=ID(r,1),y=ID(r,m);
        if(tree.ask(x,y,1,1,N)<=l)
            puts("Yes");
        else puts("No");
    }
    return 0;
}

