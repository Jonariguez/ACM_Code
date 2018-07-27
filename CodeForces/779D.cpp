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

char str[maxn],st[maxn];

int a[maxn],n,m,yes,no,vis[maxn];

bool C(int x){
    int i,j;
    for(i=1;i<=x;i++)
        vis[a[i]]=no;
    i=1;j=1;
    while(i<=n && j<=m){
        if(vis[i]==no){
            i++;continue;
        }
        if(str[i]==st[j]){
            i++;j++;
        }else i++;
    }
    if(j>m) return true;
    return false;
}

int main()
{
    int i,j;
    scanf("%s",str+1);
    scanf("%s",st+1);
    n=strlen(str+1);
    m=strlen(st+1);
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        sc(a[i]);
    int l=1,r=n-m+1,res=0;
    yes=0;no=1;
    while(l<r){
        int M=(l+r)/2;
        if(C(M)){
            res=M;
            l=M+1;
        }else
            r=M;
        yes++;no++;
    }
    printf("%d\n",res);
    return 0;
}

