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

LL a[maxn],b[maxn],S;
int n;

LL C(int x){
    for(int i=1;i<=n;i++)
        b[i]=a[i]+1LL*i*x;
    sort(b+1,b+n+1);
    LL res=0;
    for(int i=1;i<=x;i++)
        res+=b[i];
    return res;
}

int main()
{
    int i,j;
    scanf("%d%I64d",&n,&S);
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    int l=1,r=n,res=0;
    while(l<=r){
        int M=(l+r)/2;
        if(C(M)<=S){
            res=M;l=M+1;
        }else r=M-1;
    }
    printf("%d %I64d\n",res,C(res));
    return 0;
}





