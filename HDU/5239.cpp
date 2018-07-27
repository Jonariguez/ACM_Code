/****************
*PID:hdu5239
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
typedef unsigned long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const LL MOD=9223372034707292160LL;
LL a[maxn];

LL multi(LL x,LL y,LL MOD){
    LL res=0;
    x%=MOD;
    while(y){
        if(y&1)
            res=(res+x)%MOD;
        y/=2;
        x=(x*2)%MOD;
    }
    return res;
}

typedef struct Segment{
    LL sum[maxn*4];
    int cnt[maxn*4];
    void pushUp(int k){
        sum[k]=(sum[k*2]+sum[k*2+1])%MOD;
        cnt[k]=min(cnt[k*2],cnt[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k]=a[l];cnt[k]=0;return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void update(int a,int b,int k,int l,int r){
        //if(cnt[k]==30) return ;
        if(l==r){
            sum[k]=multi(sum[k],sum[k],MOD);
            cnt[k]++;
            return ;
        }
        int m=(l+r)/2;
        if(a<=l && r<=b){
            if(cnt[k]>=30) return ;
        }
        if(a<=m)
            update(a,b,lson);
        if(b>m)
            update(a,b,rson);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res+=ask(a,b,lson);
        if(b>m)
            res+=ask(a,b,rson);
        res%=MOD;
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    int kcase=1;
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        tree.build(1,1,n);
        printf("Case #%d:\n",kcase++);
        LL sum=0;
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            sum+=tree.ask(l,r,1,1,n);
            sum%=MOD;
            printf("%I64d\n",sum);
            tree.update(l,r,1,1,n);
        }
    }
    return 0;
}

