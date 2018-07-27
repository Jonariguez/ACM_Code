/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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

const int maxn=200000+10;
const int MOD=1e9+7;

LL val[maxn];
LL sum[maxn],p[maxn];
int st[maxn],Size;

LL Y(int id){
    return p[id]-sum[id]*id;
}

double G(int x,int y){
    return 1.0*(Y(x)-Y(y))/(x-y);
}

int solve(LL x){
    int l=0,r=Size-1,res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(G(st[mid],st[mid-1])<-x){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return st[res];
}


int main()
{
    int i,j,n;
    scanf("%d",&n);
    sum[0]=0;p[0]=0;
    for(i=1;i<=n;i++){
        scanf("%I64d",&val[i]);
        sum[i]=sum[i-1]+val[i];
        p[i]=p[i-1]+val[i]*i;
    }
    Size=0;
    st[Size++]=0;
    LL res=0;
    for(i=1;i<=n;i++){
        if(i==1) res=max(res,val[i]);
        else {
            int pos=solve(sum[i]);
            res=max(res,p[i]-p[pos]-(sum[i]-sum[pos])*pos);
        }
        while(Size>=2 && G(i,st[Size-1])<G(st[Size-1],st[Size-2])) Size--;
        st[Size++]=i;
    }
    Pfn(res);
    return 0;
}





