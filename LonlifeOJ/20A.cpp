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

const int maxn=400000+10;
const int N=400000+10;
int Tree[20][N];

typedef struct SS{
    vector<int> dat[maxn*4];
    void pushUp(int k,int l,int r){
        dat[k].resize(r-l+1);
        int lc=k*2,rc=k*2+1;
        merge(dat[lc].begin(),dat[lc].end(),dat[rc].begin(),dat[rc].end(),dat[k].begin());
    }

    void build(int k,int l,int r){
        if(l==r){
            dat[k].push_back(Tree[0][l]);
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k,l,r);
    }
    //²»³¬¹ývµÄ
    int ask(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            return (upper_bound(dat[k].begin(),dat[k].end(),v)-dat[k].begin());
        }
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,v,lson);
        if(b>m)
            res+=ask(a,b,v,rson);
        return res;
    }
}Tre;

Tre tp;

int sorted[N];
int toLeft[20][N];

void Build(int k,int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    int i,t;
    t=mid-l+1;
    for(i=l;i<=r;i++)
       if(Tree[k][i]<sorted[mid])
          t--;
    int L=l;
    int R=mid+1;
    for(i=l;i<=r;i++)
    {
       if(i==l)
          toLeft[k][i]=0;
       else
          toLeft[k][i]=toLeft[k][i-1];
       if(Tree[k][i]<sorted[mid])
       {
           toLeft[k][i]++;
           Tree[k+1][L++]=Tree[k][i];
       }
       else if(Tree[k][i]>sorted[mid])
       {
           Tree[k+1][R++]=Tree[k][i];
       }
       else
       {
           if(t!=0)
           {
               t--;
               toLeft[k][i]++;
               Tree[k+1][L++]=Tree[k][i];
           }
           else
               Tree[k+1][R++]=Tree[k][i];
       }
    }
    Build(k+1,l,mid);
    Build(k+1,mid+1,r);
}

int Query(int k,int l,int r,int p,int q,int t)
{
    if(p==q) return Tree[k][p];
    int s,ss;
    int mid=(l+r)>>1;
    if(l==p)
    {
        s=0;
        ss=toLeft[k][q];
    }
    else
    {
        s=toLeft[k][p-1];
        ss=toLeft[k][q]-s;
    }
    int L,R;
    if(t<=ss)
    {
        L=l+s;
        R=l+s+ss-1;
        return Query(k+1,l,mid,L,R,t);
    }
    else
    {
        L=mid-l+1+p-s;
        R=mid-l+1+q-s-ss;
        return Query(k+1,mid+1,r,L,R,t-ss);
    }
}

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&Tree[0][i]);
        sorted[i]=Tree[0][i];
    }
    tp.build(1,1,n);
    std::sort(sorted+1,sorted+n+1);
    Build(0,1,n);
    int p,q,x,k1,k2;
    while(m--)
    {
        scanf("%d%d%d%d%d",&p,&q,&x,&k1,&k2);
        int cnt=tp.ask(p,q,x,1,1,n);
        if(cnt<k1)
            printf("-1 ");
        else
            printf("%d ",Query(0,1,n,p,q,k1));
        if(q-p+1-cnt<k2)
            printf("-1\n");
        else printf("%d\n",Query(0,1,n,p,q,cnt+k2));

    }
    return 0;
}


