/*
线段树+set、gcd标记
这里的gcd标记其实就是和add标记一样，只不过是
一直都不把它算到dat里，而是一直保存到所有的
操作进行完(vector)，然后把所有的set和gcd标记都推到
叶子节点，最后再一个一个的取GCD，输出最后结果。
（独自完成）
*/
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
ll a[maxn],dat[maxn*4],set[maxn*4];
vector<ll> gcd[maxn*4];

void pushDown(int k){
    if(set[k]>=0){
        dat[k*2]=dat[k*2+1]=set[k];         //这里是左右子树，而不是dat[k]=set[k]
        gcd[k*2].clear();gcd[k*2+1].clear();
        set[k*2]=set[k*2+1]=set[k];
        set[k]=-1;
    }
    if(gcd[k].size()){
        for(int i=0;i<gcd[k].size();i++){
            gcd[k*2].push_back(gcd[k][i]);      //这里要把gcd推下去
            gcd[k*2+1].push_back(gcd[k][i]);
        }
        gcd[k].clear();
    }
}

void build(int k,int l,int r){
    set[k]=-1;gcd[k].clear();dat[k]=0;
    if(l==r){
        dat[k]=a[l];return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void Set(int a,int b,ll v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=v;dat[k]=v;gcd[k].clear();return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        Set(a,b,v,k*2,l,m);
    if(b>m)
        Set(a,b,v,k*2+1,m+1,r);
}

void update(int a,int b,ll v,int k,int l,int r){
    if(a<=l && r<=b){
        gcd[k].push_back(v);return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,v,k*2,l,m);
    if(b>m)
        update(a,b,v,k*2+1,m+1,r);
}

ll GCD(ll a,ll b){
    return b==0?a:GCD(b,a%b);
}

void print(int k,int l,int r){
    if(l==r){
        ll res=dat[k];
        for(int i=0;i<gcd[k].size();i++)
            if(res>gcd[k][i])
                res=GCD(res,gcd[k][i]);
        printf("%lld ",res);
        return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    print(k*2,l,m);
    print(k*2+1,m+1,r);
}

int main()
{
    int i,j,n,q,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        build(1,1,n);
        scanf("%d",&q);
        int o,l,r;
        ll x;
        while(q--){
            scanf("%d%d%d%lld",&o,&l,&r,&x);
            if(o==1)
                Set(l,r,x,1,1,n);
            else
                update(l,r,x,1,1,n);
        }
        print(1,1,n);
        printf("\n");
    }
    return 0;
}
