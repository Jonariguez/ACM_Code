/****************
*PID:hdu5709
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int maxm=10000000;
//T1[]:map(深度，个数),T2[]:map(颜色，深度)
int T1[maxn];  //T1[x]维护以x为根节点的子树中，深度在[l,r]的节点个数，同种颜色有多种的话，只保留深度最小的那一个。
int T2[maxn];  //T2[x]维护以x为根节点的子树中，每种颜色的最小深度。
int tot,L[maxm],R[maxm],v[maxm]; //动态线段树的加点，L[x],R[x],V[x]分别表示左右子树，和当前节点的值
int C[maxn],d[maxn],par[maxn],n;

int Insert(int p,int val,int k,int l,int r){
    int y=++tot;
    v[y]=v[k]+val;
    if(l==r) return y;
    int m=(l+r)/2;
    if(p<=m){
        L[y]=Insert(p,val,L[k],l,m);
        R[y]=R[k];
    }else {
        L[y]=L[k];
        R[y]=Insert(p,val,R[k],m+1,r);
    }
    return y;
}

int merge1(int x,int y,int l,int r){
    if(x==0 || y==0) return x+y;
    int z=++tot;
    v[z]=v[x]+v[y];
    if(l==r)
        return z;
    int m=(l+r)/2;
    L[z]=merge1(L[x],L[y],l,m);
    R[z]=merge1(R[x],R[y],m+1,r);
    return z;
}
//因为在合并时，会出现要删点的情况，我们是先合并的T1，所以合并T1时没有处理重复，合并T2时要根据T2到T1中去删点
int merge2(int x,int y,int fa,int l,int r){        //所以要记录x和y合并之后在T1中的父亲(就是要去这个父亲那里删点)
    if(x==0 || y==0) return x+y;
    int z=++tot;
    if(l==r){   //l==r时，代表颜色为l时对应的深度，我们要取x和y两棵线段树的深度小的那一个。
        if(v[x]<v[y]){  //并要从T1中删除深度大的那一个的一个节点。（因为只保留深度小的嘛，大的那一个自然要减去1）
            v[z]=v[x];
            T1[fa]=Insert(v[y],-1,T1[fa],1,n);  //把较大深度v[y]减去1
        }else {
            v[z]=v[y];
            T1[fa]=Insert(v[x],-1,T1[fa],1,n);
        }
        return z;
    }
    int m=(l+r)/2;
    L[z]=merge2(L[x],L[y],fa,l,m);  //这个父亲节点要一直是fa才对。
    R[z]=merge2(R[x],R[y],fa,m+1,r);
    return z;
}

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return v[k];
    int m=(l+r)/2,res=0;
    if(a<=m)
        res+=ask(a,b,L[k],l,m);
    if(b>m)
        res+=ask(a,b,R[k],m+1,r);
    return res;
}


int main()
{
    int i,j,m,T;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) sc(C[i]);
        for(i=2;i<=n;i++) sc(par[i]);
        for(i=1;i<=n;i++)
            d[i]=d[par[i]]+1;
        tot=1;
        for(i=1;i<=n;i++){
            T1[i]=Insert(d[i],1,1,1,n);     //在d[i]深度上+1
            T2[i]=Insert(C[i],d[i],1,1,n);  //在C[i]颜色上+d[i]
        }
        //接下来是merge,自底向上,即每一个节点和其父亲合并，先合并T1[]
        for(i=n;i>1;i--){
            T1[par[i]]=merge1(T1[par[i]],T1[i],1,n);
            T2[par[i]]=merge2(T2[par[i]],T2[i],par[i],1,n);
        }
        int last=0;
        while(m--){
            int x,D;
            scanf("%d%d",&x,&D);
            x^=last;D^=last;
            D+=d[x];
            if(D>n) D=n;
            printf("%d\n",(last=ask(1,D,T1[x],1,n)));
        }
    }
    return 0;
}


