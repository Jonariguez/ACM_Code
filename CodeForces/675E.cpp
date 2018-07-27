/****************
*PID:675E div2
*Auth:Jonariguez
*****************
½è¼ø
http://blog.csdn.net/libin66/article/details/51484474
dp[i]=dp[m]+(n-i)-(a[i]-m)    i<m<=a[i]<=a[m]<=n
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
int A[maxn];
LL dp[maxn];

typedef struct Segment{
    int sum[maxn*4];
    void pushUp(int k){
        int lc=k*2,rc=k*2+1;
        if(A[sum[lc]]>A[sum[rc]])
            sum[k]=sum[lc];
        else sum[k]=sum[rc];
    }
    void build(int k,int l,int r){
        sum[k]=0;
        if(l==r){
            sum[k]=l;
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=-1;
        if(a<=m){
            int temp=ask(a,b,lson);
            if(res==-1 || A[res]<A[temp])
                res=temp;
        }
        if(b>m){
            int temp=ask(a,b,rson);
            if(res==-1 || A[res]<A[temp])
                res=temp;
        }
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<n;i++)
            sc(A[i]);
        A[n]=n-1;
        tree.build(1,1,n);
        dp[n]=0;
        LL res=0;
        for(i=n-1;i>=1;i--){
            int pos=tree.ask(i+1,A[i],1,1,n);
            dp[i]=dp[pos]+(LL)(n-i)-(A[i]-pos);
            res+=dp[i];
        }
        printf("%I64d\n",res);
    }
    return 0;
}
