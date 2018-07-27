/****************
*PID:poj2104
*Auth:Jonariguez
*****************
主席树
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
#define ALL(x) (x).begin(),(x).end()
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

const int maxn=100000+5;
const int MOD=1e9+7;
int L[maxn<<5],R[maxn<<5],sum[maxn<<5];
vector<int> p;
int tot,T[maxn];
int a[maxn];

int build(int l,int r){
    int y=++tot;
    sum[y]=0;
    if(l==r)
        return y;
    int m=(l+r)/2;
    L[y]=build(l,m);
    R[y]=build(m+1,r);
}

int Insert(int p,int val,int l,int r,int fa){
    int rt=++tot;
    sum[rt]=sum[fa]+val;
    if(l==r)
        return rt;
    int m=(l+r)/2;
    if(p<=m){
        L[rt]=Insert(p,val,l,m,L[fa]);
        R[rt]=R[fa];
    }else {
        L[rt]=L[fa];
        R[rt]=Insert(p,val,m+1,r,R[fa]);
    }
    return rt;
}
//在[a,b]区间上找第k小，l,r为全局区间
int ask(int a,int b,int k,int l,int r){
    if(l>=r)
        return l;
    int m=(l+r)/2;
    int num=sum[L[b]]-sum[L[a]];    //对位相减
    if(num>=k)
        return ask(L[a],L[b],k,l,m);    //同时往左或者往右
    return ask(R[a],R[b],k-num,m+1,r);
}

int getID(int x){
    return upper_bound(p.begin(),p.end(),x)-p.begin();
}

int main()
{
    int i,j,n,m;
    tot=0;
    scanf("%d%d",&n,&m);
    p.clear();
    for(i=1;i<=n;i++){
        sc(a[i]);
        p.push_back(a[i]);
    }
    sort(ALL(p));
    p.erase(unique(ALL(p)),p.end());
    int N=p.size();
    T[0]=build(1,N);
    for(i=1;i<=n;i++){
        int x=getID(a[i]);
        T[i]=Insert(x,1,1,N,T[i-1]);
    }
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int res=ask(T[l-1],T[r],k,1,N);
        printf("%d\n",p[res-1]);    //注意搜索出来的结果是离散后下标的位置
    }
    return 0;
}



