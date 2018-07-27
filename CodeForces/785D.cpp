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
typedef long long Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

char str[maxn];
int lef[maxn],rht[maxn];
LL fact[maxn];

LL C(int n,int m,LL mod){
    LL temp=fact[m]*fact[n-m]%MOD;
    LL inv=quick_pow(temp,(LL)MOD-2,(LL)MOD);
    return fact[n]*inv%MOD;
}


int main()
{
    int i,j,n;
    fact[0]=1;
    for(i=1;i<=200000;i++)
        fact[i]=fact[i-1]*i%MOD;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(lef,0,sizeof(lef));
        memset(rht,0,sizeof(rht));
        int c=0;
        for(i=n;i>=1;i--){
            if(str[i]=='(')
                rht[i]=c;
            else c++;
        }
        c=0;
        for(i=1;i<=n;i++){
            if(str[i]=='('){
                lef[i]=c;
                c++;
            }
        }
        LL res=0;
        for(i=n;i>=1;i--){
            if(str[i]==')') continue;
            int mx=min(lef[i]+1,rht[i]);


