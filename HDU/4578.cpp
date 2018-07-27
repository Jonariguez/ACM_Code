/****************
*PID:hdu4578
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+5;
const int mod=10007;
LL sum[maxn*4][4],add[maxn*4],mul[maxn*4],set[maxn*4],mark[maxn*4];
int n,m;

LL Pow(LL v,int n){
    LL res=1;
    for(int i=1;i<=n;i++) res*=v;
    return res%mod;
}

void pushUp(int k){
    for(int i=1;i<=3;i++)
        sum[k][i]=(sum[k*2][i]+sum[k*2+1][i])%mod;
}

void pushDown_set(int k,int l,int r){
    if(l==r) return ;
    int lc=k*2,rc=k*2+1,i,m=(l+r)/2;;
    if(set[k]){
        set[lc]=set[rc]=set[k]%mod;
        mul[lc]=mul[rc]=1;
        add[lc]=add[rc]=0;
        for(i=1;i<=3;i++){
            sum[lc][i]=Pow(set[k],i)*(m-l+1)%mod;
            sum[rc][i]=Pow(set[k],i)*(r-m)%mod;
        }
        set[k]=0;
    }
    if(add[k]!=0 || mul[k]!=1){
       // int lc=k*2,rc=k*2+1,m=(l+r)/2;
        mul[lc]=(mul[lc]*mul[k])%mod;
        add[lc]=(add[lc]*mul[k]%mod+add[k])%mod;
        sum[lc][3]=(sum[lc][3]*Pow(mul[k],3)%mod+3*Pow(mul[k],2)%mod*sum[lc][2]%mod*add[k]%mod+
                    3*mul[k]%mod*sum[lc][1]%mod*Pow(add[k],2)%mod+Pow(add[k],3)%mod*(m-l+1)%mod)%mod;
        sum[lc][2]=(sum[lc][2]*Pow(mul[k],2)%mod+sum[lc][1]*2*mul[k]%mod*add[k]%mod+add[k]%mod*add[k]%mod*(m-l+1))%mod;
        sum[lc][1]=(sum[lc][1]*mul[k]%mod+add[k]*(m-l+1))%mod;

        mul[rc]=(mul[rc]*mul[k])%mod;
        add[rc]=(add[rc]*mul[k]%mod+add[k])%mod;
        sum[rc][3]=(sum[rc][3]*Pow(mul[k],3)%mod+3*Pow(mul[k],2)%mod*sum[rc][2]%mod*add[k]%mod+
                    3*mul[k]%mod*sum[rc][1]%mod*Pow(add[k],2)%mod+Pow(add[k],3)%mod*(r-m)%mod)%mod;
        sum[rc][2]=(sum[rc][2]*Pow(mul[k],2)%mod+sum[rc][1]*2*mul[k]%mod*add[k]%mod+add[k]%mod*add[k]%mod*(r-m))%mod;
        sum[rc][1]=(sum[rc][1]*mul[k]%mod+add[k]*(r-m))%mod;

        add[k]=0;mul[k]=1;
    }
};

void build(int k,int l,int r){
    sum[k][1]=sum[k][2]=sum[k][3]=0;
    set[k]=add[k]=0;
    mul[k]=1;
    if(l==r)
        return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void update_set(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        set[k]=(LL)v%mod;
        for(int i=1;i<=3;i++)
            sum[k][i]=Pow((LL)v,i)*(r-l+1)%mod;
        mul[k]=1;add[k]=0;
        return ;
    }
    pushDown_set(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update_set(a,b,v,k*2,l,m);
    if(b>m)
        update_set(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

void update_add(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        v%=mod;
        add[k]+=(LL)v;
        int L=r-l+1;
        sum[k][3]=(sum[k][3]+3*sum[k][2]*v%mod+3*sum[k][1]*v%mod*v%mod+v%mod*v%mod*v%mod*L%mod)%mod;
        sum[k][2]=(sum[k][2]+2*sum[k][1]*v%mod+v%mod*v%mod*L%mod)%mod;
        sum[k][1]=(sum[k][1]+v%mod*L)%mod;
        return ;
    }
    pushDown_set(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update_add(a,b,v,k*2,l,m);
    if(b>m)
        update_add(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

void update_mul(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        add[k]=add[k]*v%mod;
        mul[k]=mul[k]*v%mod;
        int L=r-l+1;
        sum[k][3]=(sum[k][3]*v%mod*v%mod*v)%mod;
        sum[k][2]=(sum[k][2]*v%mod*v)%mod;
        sum[k][1]=(sum[k][1]*v)%mod;
        return ;
    }
    pushDown_set(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update_mul(a,b,v,k*2,l,m);
    if(b>m)
        update_mul(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

LL ask(int a,int b,int c,int k,int l,int r){
    if(a<=l && r<=b)
        return sum[k][c]%mod;
    pushDown_set(k,l,r);
    int m=(l+r)/2;
    LL res=0;
    if(a<=m)
        res+=ask(a,b,c,k*2,l,m);
    if(b>m)
        res+=ask(a,b,c,k*2+1,m+1,r);
   // pushUp(k);
    return res;
}

int main()
{
    int i,j,T;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        int op,x,y,c;
        build(1,1,n);
        while(m--){
            scanf("%d%d%d%d",&op,&x,&y,&c);
            if(op==1)
                update_add(x,y,c,1,1,n);
            else if(op==2)
                update_mul(x,y,c,1,1,n);
            else if(op==3)
                update_set(x,y,c,1,1,n);
            else printf("%lld\n",ask(x,y,c,1,1,n)%mod);
        }
    }
    return 0;
}
