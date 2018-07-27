#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
//sum是该区间最长连续长度  lsum是从区间最左端开始最长连续长度，rsum是右端，mark为标记 -1无 0置空 1置满
int sum[maxn*4],lsum[maxn*4],rsum[maxn*4],mark[maxn*4];

int Max(int a,int b,int c){
    return max(a,max(b,c));
}

void pushUp(int k,int l,int r){     //父亲节点的lsum和rsum分别为左儿子的lsum、右儿子的rsum
    lsum[k]=lsum[k*2];rsum[k]=rsum[k*2+1];
    int m=(l+r)/2;
    if(lsum[k]==m-l+1)  lsum[k]+=lsum[k*2+1];   //如果lsum覆盖了整个左半区间，那么lsum就应该把右半区间(即右儿子)的lsum接上
    if(rsum[k]==r-m)    rsum[k]+=rsum[k*2];     //原理同上
    sum[k]=Max(sum[k*2],sum[k*2+1],rsum[k*2]+lsum[k*2+1]);      //父亲节点的sum应该是左右儿子的sum值和跨区间的那段连续长度 三者的最长
}

void pushDown(int k,int l,int r){
    if(mark[k]!=-1){
        mark[k*2]=mark[k*2+1]=mark[k];
        int m=(l+r)/2;
        if(mark[k]==1){             //置满就是所有连续的长度都是0
            sum[k*2]=lsum[k*2]=rsum[k*2]=sum[k*2+1]=lsum[k*2+1]=rsum[k*2+1]=0;
        }else if(mark[k]==0){
            sum[k*2]=m-l+1;lsum[k*2]=rsum[k*2]=m-l+1;
            sum[k*2+1]=r-m;lsum[k*2+1]=rsum[k*2+1]=r-m;
        }
        mark[k]=-1;
    }
}



void build(int k,int l,int r){
    if(l==r){
        sum[k]=lsum[k]=rsum[k]=1;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k,l,r);
}

void update(int a,int b,int k,int l,int r,int v){
    if(a<=l && b>=r){
        mark[k]=v;      //标记上
        if(v)
            sum[k]=lsum[k]=rsum[k]=0;
        else
            sum[k]=lsum[k]=rsum[k]=r-l+1;
        return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,k*2,l,m,v);
    if(b>m)
        update(a,b,k*2+1,m+1,r,v);
    pushUp(k,l,r);
}

int query(int L,int k,int l,int r){
    if(l==r) return l;
    int m=(l+r)/2;
    pushDown(k,l,r);
    if(sum[k*2]>=L)     //注意这三者return顺序不能变，因为要求r最小
        return query(L,k*2,l,m);        //递归左子树
    else if(rsum[k*2]+lsum[k*2+1]>=L)
        return m-rsum[k*2]+1;           //这种情况是可以直接返回结果，比如右子树不一定就是rsum表示的区间，即便它
    else                                //比L长。因为可能在这之前还有区间符合，毕竟我们要的是开头最小的那个区间
        return query(L,k*2+1,m+1,r);    //递归右子树
}

int main()
{
    int i,n,m,p,x,d;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    memset(mark,-1,sizeof(mark));
    while(m--){
        scanf("%d",&p);
        if(p==1){
            scanf("%d",&d);
            if(sum[1]<d){
                printf("0\n");
                continue;
            }
            int t=query(d,1,1,n);
            printf("%d\n",t);
            update(t,t+d-1,1,1,n,1);
        }else {
            scanf("%d%d",&x,&d);
            update(x,x+d-1,1,1,n,0);
        }
    }
    return 0;
}

