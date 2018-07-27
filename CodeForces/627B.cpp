/****************
*PID:627b 8vc
*Auth:Jonariguez
*****************
线段树
suma[k]:区间里每天产a个的话，能生成多少个
sumb[k]同理
//needa[k]:区间每天产a个的话，为了满足全区间每天都产a个还需要多少个
//havea[k]:区间每天产a个的话，在满足此条件的情况下，还剩多少个可以往后分配。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+5;
int a,b;

struct Segment{
    int sum[maxn*4],suma[maxn*4],sumb[maxn*4];
    void pushUp(int k){
        int lc=k*2,rc=k*2+1;
        sum[k]=sum[lc]+sum[rc];
        suma[k]=suma[lc]+suma[rc];
        sumb[k]=sumb[lc]+sumb[rc];
    }
    void build(int k,int l,int r){
        sum[k]=suma[k]=0;
        sumb[k]=0;
        if(l==r){
            return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            if(suma[k]+v>=a)
                suma[k]=a;
            else suma[k]+=v;
            if(sumb[k]+v>=b)
                sumb[k]=b;
            else sumb[k]+=v;
            return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,k*2,l,m);
        else update(p,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int A,int B,int f,int k,int l,int r){
        if(A<=l && r<=B){
            if(f)
                return sumb[k];
            return suma[k];
        }
        int m=(l+r)/2;
        int res=0;
        if(A<=m)
            res+=ask(A,B,f,k*2,l,m);
        if(B>m)
            res+=ask(A,B,f,k*2+1,m+1,r);
        return res;
    }
}tree;

int main()
{
    int i,j,k,n,q;
    while(scanf("%d%d%d%d%d",&n,&k,&a,&b,&q)!=EOF){
        tree.build(1,1,n);
        while(q--){
            int o,d,v,p;
            scanf("%d",&o);
            if(o==1){
                scanf("%d%d",&d,&v);
                tree.update(d,v,1,1,n);
            }else {
                scanf("%d",&p);
                int res=0;
                if(p>1)
                    res+=tree.ask(1,p-1,1,1,1,n);
                if(p+k-1<n)
                    res+=tree.ask(p+k,n,0,1,1,n);
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
