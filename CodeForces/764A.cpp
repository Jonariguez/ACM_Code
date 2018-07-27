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

const int maxn=200000+10;
const int MOD=1e9+7;
/*
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,n,m,z;
    while(scanf("%d%d%d",&n,&m,&z)!=EOF){
        printf("%d\n",z/(n*m/gcd(n,m)));
    }
    return 0;
}
764B
*/

int a[maxn];

void Swap(int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int main()
{
    int i,j,cnt,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n/2;i++){
            if(i&1)
                Swap(i,n-i+1);
        }
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        puts("");
    }
    return 0;
}

