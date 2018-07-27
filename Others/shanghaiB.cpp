#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+5;
int n,M;
ll sum[maxn*4];

void pushUp(int k){
    sum[k]=(sum[k*2]*sum[k*2+1])%M;
}

void build(int k,int l,int r){
    sum[k]=0;
    if(l==r){
        sum[k]=1;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,ll v,int k,int l,int r){
    if(l==r){
        sum[k]=v;return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        update(a,v,k*2,l,m);
    else
        update(a,v,k*2+1,m+1,r);
    pushUp(k);
}


int main()
{
    int i,j,T,res,kcase=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",kcase++);
        scanf("%d%d",&n,&M);
        build(1,1,n);
        ll x,y;
        for(i=1;i<=n;i++){
            scanf("%lld%lld",&x,&y);
            if(x==1){
                update(i,y,1,1,n);
                printf("%lld\n",sum[1]);
            }else {
                update(y,1,1,1,n);
                printf("%lld\n",sum[1]);
            }
        }
    }
    return 0;
}

