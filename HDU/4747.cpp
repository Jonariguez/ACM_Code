#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=200000+10;
int a[maxn],mex[maxn],Next[maxn];  //Next[i]表示在i之后，下一个等于a[i]的位置，等于n+1说明不存在
ll sum[maxn*4],Max[maxn*4],set[maxn*4];
map<int,int> mp;

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
    Max[k]=max(Max[k*2],Max[k*2+1]);
}

void pushDown(int k,int l,int r){
    if(set[k]>=0){
        int m=(l+r)/2,lc=k*2,rc=k*2+1;
        sum[lc]=(ll)set[k]*(m-l+1);
        sum[rc]=(ll)set[k]*(r-m);
        Max[lc]=Max[rc]=set[k];
        set[lc]=set[rc]=set[k];
        set[k]=-1;
    }
}

void build(int k,int l,int r){
    set[k]=-1;
    if(l==r){
        sum[k]=Max[k]=mex[l];return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void Set(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=v;sum[k]=(ll)v*(r-l+1);Max[k]=v;return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        Set(a,b,v,k*2,l,m);
    if(b>m)
        Set(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

int Get(int v,int k,int l,int r){
    if(l==r) return l;
    pushDown(k,l,r);
    int m=(l+r)/2,t;
    if(v<Max[k*2])
        t=Get(v,k*2,l,m);
    else t=Get(v,k*2+1,m+1,r);
    pushUp(k);
    return t;
}


int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        mp.clear();
        int cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]=1;
            while(mp.find(cnt)!=mp.end()) cnt++;
            mex[i]=cnt;
        }
        mp.clear();
        for(i=n;i>0;i--){
            if(mp.count(a[i])==0) Next[i]=n+1;
            else Next[i]=mp[a[i]];
            mp[a[i]]=i;
        }
        build(1,1,n);
        ll res=0;
        for(i=1;i<=n;i++){
            res+=sum[1];
            if(Max[1]>=a[i]){
                int l=Get(a[i],1,1,n);
                int r=Next[i];
                if(l<r)
                    Set(l,r-1,a[i],1,1,n);
            }
            Set(i,i,0,1,1,n);
        }
        printf("%lld\n",res);
    }
    return 0;
}

