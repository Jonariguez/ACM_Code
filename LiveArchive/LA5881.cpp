/****************
*PID:la5881
*Auth:Jonariguez
*****************
Ô¤´¦Àí+Ïß¶ÎÊ÷
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

const int maxn=1000000+10;
int A[maxn],pre[maxn];
map<int,int> mp;

struct Segment{
    int sum[maxn*4];
    void pushUp(int k){
        int lc=k*2,rc=k*2+1;
        sum[k]=max(sum[lc],sum[rc]);
    }
    void build(int k,int l,int r){
        sum[k]=0;
        if(l==r){
            sum[k]=pre[l];
            return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=-1;
        if(b<=m)
            res=max(res,ask(a,b,k*2,l,m));
        else if(a>m)
            res=max(res,ask(a,b,k*2+1,m+1,r));
        else {
            res=max(res,ask(a,b,k*2,l,m));
            res=max(res,ask(a,b,k*2+1,m+1,r));
        }
        return res;
    }
}tree;

int main()
{
    int i,j,n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        mp.clear();
        memset(pre,0,sizeof(pre));
        for(i=1;i<=n;i++){
            sc(A[i]);
            pre[i]=mp[A[i]];
            mp[A[i]]=i;
        }
        tree.build(1,1,n);
      /*  while(m--){
            int x,y;
            sc(x);sc(y);
            int yes=1,temp;
            for(temp=x;temp<=y;temp++){
                if(pre[temp]>=x){
                    yes=0;break;
                }
            }
            if(yes)
                printf("OK\n");
            else
                printf("%d\n",a[temp]);
        }*/
        while(m--){
            int x,y;
            sc(x);sc(y);
            int temp=tree.ask(x,y,1,1,n);
            if(temp<x)
                printf("OK\n");
            else
                printf("%d\n",A[temp]);
        }
        printf("\n");
    }
    return 0;
}


