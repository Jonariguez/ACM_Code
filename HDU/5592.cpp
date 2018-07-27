/****************
*PID:hdu5592
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int inv[maxn];

struct seg{
    int sum[maxn*4],a[maxn];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k]=1;return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    int update(int v,int k,int l,int r){
        if(l==r){
            sum[k]=0;return l;
        }
        int m=(l+r)/2,res;
        if(v<=sum[k*2+1])
            res=update(v,k*2+1,m+1,r);
        else res=update(v-sum[k*2+1],k*2,l,m);
        pushUp(k);
        return res;
    }
};

seg tree;
int res[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&inv[i]);
        tree.build(1,1,n);
        inv[0]=0;
        for(i=n;i>1;i--)
            inv[i]-=inv[i-1];
        for(i=n;i>=1;i--){
            int t=inv[i]+1;
            res[i]=tree.update(t,1,1,n);
        }
        for(i=1;i<=n;i++)
            printf("%d%c",res[i],i==n?'\n':' ');
    }
    return 0;
}
