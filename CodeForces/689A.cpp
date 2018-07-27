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
int a[maxn];
int b[111],i;

bool check_d(int n){
    int i;
    for(i=1;i<=n;i++){
        if(a[i]==7 || a[i]==0 || a[i]==9) return false;
    }
    return true;
}

bool check_u(int n){
    int i;
    for(i=1;i<=n;i++){
        if(a[i]==1 || a[i]==2 || a[i]==3) return false;
    }
    return true;
}

bool check_l(int n){
    int i;
    for(i=1;i<=n;i++)
        b[i]=a[i];
    for(i=1;i<=n;i++){
        if(b[i]==0 || b[i]==1 || b[i]==4 || b[i]==7) return false;
    }
    return true;
}

bool check_r(int n){
    int i;
    for(i=1;i<=n;i++)
        b[i]=a[i];
    for(i=1;i<=n;i++){
        if(b[i]==0 || b[i]==3 || b[i]==6 || b[i]==9) return false;
    }
    return true;
}

char str[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        for(i=1;i<=n;i++)
            a[i]=(str[i]-'0');
        if(check_d(n) || check_u(n) || check_l(n) || check_r(n))
            puts("NO");
        else puts("YES");
    }
    return 0;
}

