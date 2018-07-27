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
const int INF=1e9+77;
int a[maxn],b[maxn];
int ra[maxn],rb[maxn];

typedef struct Segment{
    int sum1[maxn*4],sum2[maxn*4];
    void pushUp(int k){
        sum1[k]=max(sum1[k*2],sum1[k*2+1]);
        sum2[k]=min(sum2[k*2],sum2[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            sum1[k]=a[l];
            sum2[k]=b[l];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    int askmax(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum1[k];
        int m=(l+r)/2,res=-INF;
        if(a<=m)
            res=max(res,askmax(a,b,lson));
        if(b>m)
            res=max(res,askmax(a,b,rson));
        return res;
    }
    int askmin(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum2[k];
        int m=(l+r)/2,res=INF;
        if(a<=m)
            res=min(res,askmin(a,b,lson));
        if(b>m)
            res=min(res,askmin(a,b,rson));
        return res;
    }
}Tree;

Tree tree;
int n;

bool Cl(int i,int r){
    return tree.askmax(i,r,1,1,n)-tree.askmin(i,r,1,1,n)<=tree.askmax(i,r+1,1,1,n)-tree.askmin(i,r+1,1,1,n);
}


int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sc(a[i]);
    }
    for(i=1;i<=n;i++)
        sc(b[i]);
    tree.build(1,1,n);
    LL res=0;
    for(i=1;i<=n;i++){
        int ansl=0,ansr=0,l=i,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(Cl(i,m)){
                ansl=m;
                r=m-1;
            }else l=m+1;
        }
        l=i;r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(Cl(i,m)){
                ansr=m;
                l=m+1;
            }else r=m-1;
        }
        res+=ansr-ansl+1;
    }
    Pfn(res);
    return 0;
}



