/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int MOD=1e9+7;

LL sum[maxn];
int a[maxn],st[maxn],head,tail;

LL getUp(int k,int j){
    return sum[k]-sum[j];
}

int getDown(int k,int j){
    return k-j;
}

void add(int i){
    while(head<tail-1 && getUp(i,st[tail-1])*getDown(st[tail-1],st[tail-2])<=getUp(st[tail-1],st[tail-2])*getDown(i,st[tail-1])) tail--;
    st[tail++]=i;
}

bool better(int k,int j,int i){
    return getUp(i,j)*getDown(j,k)>=getUp(j,k)*getDown(i,j);
}

int ask(int i){
    int left=head,right=tail-1,res=left;
    if(head==tail-1) return st[head];
    while(left<=right){
        int m=(left+right)/2;
        if(better(st[m-1],st[m],i)){
            res=m;left=m+1;
        }else right=m-1;
    }
    return st[res];
}

int main()
{
    int i,n,F;
    scanf("%d%d",&n,&F);
    sum[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    head=tail=0;
    st[tail++]=0;
    LL x=0,y=1;
    for(i=F;i<=n;i++){
        int p=ask(i);
        if(x*(i-p)<y*(sum[i]-sum[p])){
            x=sum[i]-sum[p];
            y=i-p;
        }
        add(i-F+1);
    }
    cout<<x*1000/y<<endl;
    return 0;
}




