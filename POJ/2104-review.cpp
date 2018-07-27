/****************
*PID:poj2104
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
int A[maxn];

struct Segment{
    vector<int> sum[maxn*4];
    void pushUp(int k,int l,int r){
        int lc=k*2,rc=k*2+1;
        sum[k].resize(r-l+1);
        merge(sum[lc].begin(),sum[lc].end(),sum[rc].begin(),sum[rc].end(),sum[k].begin());
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k].push_back(A[l]);return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k,l,r);
    }
    int ask(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            return lower_bound(sum[k].begin(),sum[k].end(),v)-sum[k].begin();
        }
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,v,k*2,l,m);
        if(b>m)
            res+=ask(a,b,v,k*2+1,m+1,r);
        return res;
    }
}tree;

int main()
{
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    tree.build(1,1,n);
    sort(A+1,A+n+1);
    while(m--){
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int l=1,r=n+1;  //区间[l,r)
        while(l<r-1){
            int M=(l+r)/2;
            int c=tree.ask(a,b,A[M],1,1,n);
            if(c<k)     //第k小，那么比它小的应该有k-1个，故这里不能=
                l=M;
            else r=M;
        }
        printf("%d\n",A[l]);
    }
    return 0;
}
