/****************
*PID:hdu5654
*Auth:Jonariguez
*****************
处理以每个位置开始的满足要求的三元组，a[i],a[i+1],a[i+2]
然后对每个三元组map一下，用pre[i]表示和第i个三元组同的三元组
前一次出现的位置，如果全面没出现过就pre[i]=0,如果不满足
三元组要求的是pre[i]=n。这样对于查询[L,R],,只需要计算区间[L,R-2]
里pre值小于L的个数就是答案。
用归并树维护查询即可。
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

const int maxn=200000+10;
int pre[maxn],a[maxn];
pair<int,pair<int,int> > pp;
map<pair<int,pair<int,int> >,int> mp;

struct Tree{
    vector<int> sum[maxn*4];
    void pushUp(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        sum[k].clear();
        sum[k].resize(r-l+1);
        merge(sum[lc].begin(),sum[lc].end(),sum[rc].begin(),sum[rc].end(),sum[k].begin());
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k].clear();
            sum[k].push_back(pre[l]);
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k,l,r);
    }
    int ask(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b)
            return upper_bound(sum[k].begin(),sum[k].end(),v)-sum[k].begin();
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,v,lson);
        if(b>m)
            res+=ask(a,b,v,rson);
        return res;
    }
}tree;

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        for(i=1;i<=n;i++)
            sc(a[i]);
        if(n<3){
            scanf("%d",&m);
            while(m--){
                int x,y;
                sc(x);sc(y);
                puts("0");
            }
            continue;
        }
        for(i=1;i<=n-2;i++){
            if(!(a[i]<=a[i+1] && a[i+1]<=a[i+2]))
                pre[i]=n;
            else {
                pp=make_pair(a[i],make_pair(a[i+1],a[i+2]));
                if(mp[pp]!=0)
                    pre[i]=mp[pp];
                else pre[i]=0;
                mp[pp]=i;
            }
        }
        pre[n-1]=pre[n]=n;
        tree.build(1,1,n);
        scanf("%d",&m);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(y-x<2)
                puts("0");
            else printf("%d\n",tree.ask(x,y-2,x-1,1,1,n));
        }
    }
    return 0;
}


