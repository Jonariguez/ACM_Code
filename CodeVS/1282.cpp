/****************
*PID:cdvs1282
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
vector<int> res;

struct segment{
    int sum[maxn*4];
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
    void insert(int p,int k,int l,int r){
        if(l==r){
            sum[k]=0;res.push_back(l);return ;
        }
        int m=(l+r)/2;
        if(p<=sum[k*2])
            insert(p,k*2,l,m);
        else insert(p-sum[k*2],k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a>b) return 0;
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,k*2,l,m);
        if(b>m)
            res+=ask(a,b,k*2+1,m+1,r);
        return res;
    }
}tree;

int main()
{
    int i,j,n,m,cnt,temp;
    scanf("%d%d",&n,&m);
    temp=n*(n+1)/2;
    tree.build(1,1,n);
    int tot=n,now=1;
    for(i=0;i<n-1;i++){
        int t=m%tot;
        if(t==0) t=tot;
        cnt=tree.ask(now,n,1,1,n);
        if(cnt<t){
            t-=cnt;
        }
        else{//printf("??\n");
            t+=tree.ask(1,now-1,1,1,n);
        }
        tree.insert(t,1,1,n);
        now=res[i];
        tot--;
    }
    for(i=0;i<res.size();i++){
        printf("%d ",res[i]);temp-=res[i];
    }
    printf("%d\n",temp);
    return 0;
}
