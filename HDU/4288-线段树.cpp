/*
线段树 (因为要离散化，所以离线)
对于每个节点对应的区间都要保存该区间
里的序列中，下标对5取余分类求和，用
sum[k][0..4]保存，重点是左右区间合并时，
父节点的sum[][0..4]与左子区间的sum[][0..4]
分别对应，那么和右子区间的对应关系取决于
左子区间的元素个数。
(提示:i+5*t>cnt[k*2]+x,x即是落在右区间的位置，
则x=(i-cnt[k*2])%5,然后取整使x落在[0,5)即可
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+5;
ll sum[maxn*4][5];
int cnt[maxn*4],a[maxn];

struct OP{
    int type,x;
}s[maxn];

void pushUp(int k){
    int lc=k*2,rc=k*2+1;
    cnt[k]=cnt[k*2]+cnt[k*2+1];
    for(int i=0;i<5;i++)
        sum[k][i]=sum[k*2][i]+sum[k*2+1][((i-cnt[k*2])%5+5)%5];
}

void build(int k,int l,int r){
    cnt[k]=0;
    for(int i=0;i<5;i++)
        sum[k][i]=0;
    if(l==r) return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void Insert(int a,int v,int k,int l,int r){
    if(l==r){
        cnt[k]++;
        sum[k][1]=v;
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,v,k*2,l,m);
    else
        Insert(a,v,k*2+1,m+1,r);
    pushUp(k);
}

void Delete(int a,int k,int l,int r){
    if(l==r){
        cnt[k]--;sum[k][1]=0;
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Delete(a,k*2,l,m);
    else
        Delete(a,k*2+1,m+1,r);
    pushUp(k);
}

int getIndex(int x,int n){
    return (lower_bound(a,a+n,x)-a)+1;
}

int main()
{
    int i,j,n,x;
    char o[10];
    while(scanf("%d",&n)!=EOF){
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%s",o);
            if(o[0]=='a'){
                scanf("%d",&x);
                s[i].type=1;s[i].x=x;
                a[tot++]=x;
            }else if(o[0]=='d'){
                scanf("%d",&x);
                s[i].type=2;s[i].x=x;
                a[tot++]=x;
            }else
                s[i].type=3;
        }
        sort(a,a+tot);
        tot=unique(a,a+tot)-a;
        build(1,1,tot);
        for(i=0;i<n;i++){
            if(s[i].type==1)
                Insert(getIndex(s[i].x,tot),s[i].x,1,1,tot);
            else if(s[i].type==2)
                Delete(getIndex(s[i].x,tot),1,1,tot);
            else
                printf("%lld\n",sum[1][3]);
        }
    }
    return 0;
}


