/****************
*PID:bzoj3289
*Auth:Jonariguez
*****************
莫队
转移时logn的，即用BIT维护逆序对。
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

const int maxn=50000+10;
int a[maxn],bit[1000005],res[maxn],N,n,m,unit;

struct Query{
    int L,R,id;
}s[maxn];

int cmp(const Query &x,const Query &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

void add(int i,int v){
    while(i<=N){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

void Mo(){
    int L=1,R=0,len=0,i,now=0;  //涉及到在某区间比自己大的值有多少，而BIT是维护比自己小，故还要维护区间长度。
    for(i=1;i<=m;i++){
        while(R<s[i].R){
            R++;
            len++;
            add(a[R],1);
            now+=len-sum(a[R]);
        }
        while(R>s[i].R){
            now-=len-sum(a[R]);
            add(a[R],-1);
            R--;len--;
        }
        while(L<s[i].L){
            now-=sum(a[L]-1);
            add(a[L],-1);
            L++;len--;
        }
        while(L>s[i].L){
            L--;
            len++;
            add(a[L],1);
            now+=sum(a[L]-1);
        }
        res[s[i].id]=now;
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    N=0;
    for(i=1;i<=n;i++){
        sc(a[i]);
        N=max(N,a[i]);
    }
    sc(m);
    unit=(int)sqrt(n);
    for(i=1;i<=m;i++){
        scanf("%d%d",&s[i].L,&s[i].R);
        s[i].id=i;
    }
    sort(s+1,s+m+1,cmp);
    Mo();
    for(i=1;i<=m;i++)
        printf("%d\n",res[i]);
    return 0;
}


