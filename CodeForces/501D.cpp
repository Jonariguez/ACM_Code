/****************
*PID:501d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+5;
int a[maxn],p[maxn],q[maxn],c[maxn];

struct segment_tree{
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
    void update(int x,int k,int l,int r){
        if(l==r){
            sum[k]=0;return ;
        }
        int m=(l+r)/2,res;
        if(x<=m)
            update(x,k*2,l,m);
        else update(x,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask(a,b,k*2,l,m);
        if(b>m)
            res+=ask(a,b,k*2+1,m+1,r);
        return res;
    }
    int search(int x,int k,int l,int r){
        if(l==r){
            sum[k]=0;return l;
        }
        int m=(l+r)/2,res;
        if(x<=sum[k*2])
            res=search(x,k*2,l,m);
        else res=search(x-sum[k*2],k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}tp,tc;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        tp.build(1,1,n);
        for(i=1;i<=n;i++){  //确定p序列的康托展开的康托系数
            scanf("%d",&a[i]);
            a[i]++;
            if(a[i]==1){
                p[i]=0;tp.update(1,1,1,n);
            }else {
                p[i]=tp.ask(1,a[i]-1,1,1,n);    //这里不用-1
                tp.update(a[i],1,1,n);
            }
        }
        tp.build(1,1,n);
        for(i=1;i<=n;i++){  //确定p序列的康托展开的康托系数
            scanf("%d",&a[i]);
            a[i]++;
            if(a[i]==1){
                q[i]=0;tp.update(1,1,1,n);
            }else {
                q[i]=tp.ask(1,a[i]-1,1,1,n);
                tp.update(a[i],1,1,n);
            }
        }
        memset(c,0,sizeof(c));
        for(i=n;i>=1;i--){  //确定p+q序列的康托展开的康托系数，由低位向高位。
            c[i]+=p[i]+q[i];
            if(c[i]>=n-i+1){
                c[i]-=n-i+1;
                c[i-1]++;
            }
        }
        vector<int> res;
        tc.build(1,1,n);
        for(i=1;i<=n;i++)
            res.push_back(tc.search(c[i]+1,1,1,n));
        for(i=0;i<res.size();i++)
            printf("%d ",res[i]-1);
        printf("\n");
    }
    return 0;
}
