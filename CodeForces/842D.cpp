/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=600000+10;
const int MOD=1e9+7;
int a[maxn],cnt[maxn*4];

void pushUp(int k){
    cnt[k]=cnt[k*2]+cnt[k*2+1];
}

void build(int k,int l,int r){
    if(l==r){
        cnt[k]=0;return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    pushUp(k);
}

void Insert(int v,int k,int l,int r){
    if(l==r){
        cnt[k]=1;return ;
    }
    int m=(l+r)/2;
    if(v<=m)
        Insert(v,lson);
    else Insert(v,rson);
    pushUp(k);
}

int s[25];

int ask(int b,int k,int l,int r){
    if(l==r) return 0;
    int m=(l+r)/2;
    if(s[b]){
        if(cnt[k*2+1]==r-m)
            return (1<<b)+ask(b-1,lson);
        else return ask(b-1,rson);
    }else {
        if(cnt[k*2]==m-l+1)
            return (1<<b)+ask(b-1,rson);
        else return ask(b-1,lson);
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    int N=524287;
    build(1,0,N);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        Insert(a[i],1,0,N);
    }
    int res=0;
    while(m--){
        int x;
        scanf("%d",&x);
        res^=x;
        for(i=0;i<19;i++)
            if((res>>i)&1) s[i]=1;
            else s[i]=0;
      //  for(i=0;i<19;i++)
      //      if(x&(1<<i)) s[i]^=1;
        printf("%d\n",ask(18,1,0,N));
    }
    return 0;
}


