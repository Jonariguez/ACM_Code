/****************
*PID:cdvs1217
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+5;
const LL INF=1e17+10;
LL d[maxn];
int s[maxn],t[maxn];

inline int read(){
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    int x=0;
    while(isdigit(c)){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}

struct segment{
    LL sum[maxn*4],add[maxn*4],res;
    void pushUp(int k){
        sum[k]=min(sum[k*2],sum[k*2+1]);
    }
    void pushDown(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        if(add[k]){
            add[lc]+=add[k];add[rc]+=add[k];
            sum[lc]+=add[k];
            sum[rc]+=add[k];
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        add[k]=0;
        if(l==r){
            sum[k]=(LL)read();
            return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    void Add(int a,int b,LL v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=v;return ;
        }
        int m=(l+r)/2;
        pushDown(k,l,r);
        if(a<=m)
            Add(a,b,v,k*2,l,m);
        if(b>m)
            Add(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    void ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b){
            res=min(res,sum[k]);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            ask(a,b,k*2,l,m);
        if(b>m)
            ask(a,b,k*2+1,m+1,r);
        pushUp(k);
    }
}tree;

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    tree.build(1,1,n);
    for(i=1;i<=m;i++){
        d[i]=(LL)read();s[i]=read();t[i]=read();
    }
    int yes=0,res;
    for(i=1;i<=m;i++){
        tree.res=INF;
        tree.ask(s[i],t[i],1,1,n);
        if(tree.res<d[i]){
            yes=-1;break;
        }
        tree.Add(s[i],t[i],-d[i],1,1,n);
    }
    printf("%d\n",yes);
    if(yes) printf("%d\n",i);
    return 0;
}
