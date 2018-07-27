/****************
*PID:hdu5649
*Auth:Jonariguez
*****************
*/
#pragma comment(linker, "/STACK:102400000,102400000")
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
int a[maxn],o[maxn],L[maxn],R[maxn],n,m,k;

struct Segment{
    int sum[maxn*4],set[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        if(set[k]>=0){
            int lc=k*2,rc=k*2+1,m=(l+r)/2;
            set[lc]=set[rc]=set[k];
            sum[lc]=set[k]*(m-l+1);
            sum[rc]=set[k]*(r-m);
            set[k]=-1;
        }
    }
    void build(int k,int l,int r,int f){
        set[k]=-1;sum[k]=0;
        if(l==r){
            sum[k]=(a[l]>f?1:0);return ;
        }
        int m=(l+r)/2;
        build(lson,f);
        build(rson,f);
        pushUp(k);
    }
    void Set(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            set[k]=v;sum[k]=v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,lson);
        if(b>m)
            Set(a,b,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,lson);
        if(b>m)
            res+=ask(a,b,rson);
        pushUp(k);
        return res;
    }
}tree;

bool C(int x){
    int i;
    tree.build(1,1,n,x);
    for(i=1;i<=m;i++){
        if(o[i]==0){    //increasing
            int s=tree.ask(L[i],R[i],1,1,n);
            if(s>0 && s<R[i]-L[i]+1){
                tree.Set(R[i]-s+1,R[i],1,1,1,n);
                tree.Set(L[i],R[i]-s,0,1,1,n);
            }
        }else {
            int s=tree.ask(L[i],R[i],1,1,n);
            if(s>0 && s<R[i]-L[i]+1){
                tree.Set(L[i],L[i]+s-1,1,1,1,n);
                tree.Set(L[i]+s,R[i],0,1,1,n);
            }
        }
    }
    return tree.ask(k,k,1,1,n);
}

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            sc(a[i]);
        for(i=1;i<=m;i++){
            sc(o[i]);sc(L[i]);sc(R[i]);
        }
        sc(k);
        int l=0,r=n;
        while(l<r-1){
            int M=(l+r)/2;
            if(C(M))
                l=M;
            else r=M;
        }
        printf("%d\n",r);
    }
    return 0;
}

