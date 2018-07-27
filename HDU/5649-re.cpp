/****************
*PID:hdu5649
*Auth:Jonariguez
*****************
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
int n,k,m;
int o[maxn],L[maxn],R[maxn],a[maxn];

typedef struct Segment{
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
    void build(int k,int l,int r,int v){
        set[k]=-1;sum[k]=0;
        if(l==r){
            sum[k]=(a[l]>v?1:0);
            return ;
        }
        int m=(l+r)/2;
        build(lson,v);
        build(rson,v);
        pushUp(k);
    }
    void Set(int a,int b,int v,int k,int l,int r){
        if(a>b) return ;
        if(a<=l && r<=b){
            set[k]=v;sum[k]=v*(r-l+1);
            return ;
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
}Tree;

Tree tree;

bool C(int x){
    int i,j,cnt;
    tree.build(1,1,n,x);
    for(i=1;i<=m;i++){
        if(o[i]){
            cnt=tree.ask(L[i],R[i],1,1,n);
            if(cnt==0) continue;
            tree.Set(L[i],L[i]+cnt-1,1,1,1,n);
            tree.Set(L[i]+cnt,R[i],0,1,1,n);
        }else {
            cnt=tree.ask(L[i],R[i],1,1,n);
            if(cnt==0) continue;
            int l=R[i]-L[i]+1;
            tree.Set(R[i]-cnt+1,R[i],1,1,1,n);
            tree.Set(L[i],R[i]-cnt,0,1,1,n);
        }
    }
    int temp=tree.ask(k,k,1,1,n);
    return temp==0;
}

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        sc(n);sc(m);
        for(i=1;i<=n;i++)
            sc(a[i]);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&o[i],&L[i],&R[i]);
        sc(k);
        int l=1,r=n,res=0;
        while(l<=r){
            int M=(l+r)/2;
           // printf("M=%d\n",M);
            if(C(M)){
                res=M;
                r=M-1;
            }else l=M+1;
        }
        printf("%d\n",res);
    }
    return 0;
}

/*
6 0
1 2 3 4 5 6
*/



