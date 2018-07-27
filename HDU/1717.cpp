/****************
*PID:hdu1717
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

char str[22];
int fact[12];

void solve(int &a,int &b){
    int i=3,j;
    int n=strlen(str+1);
    while(i<=n){
        if(str[i]=='(') break;
        i++;
    }
    if(i>n){
        b=fact[n-2];
        a=0;
        for(i=3;i<=n;i++)
            a=a*10+(str[i]-'0');
        return ;
    }else if(i==3){
        b=fact[n-4]-1;
        a=0;
        for(i=4;i<n;i++)
            a=a*10+(str[i]-'0');
        return ;
    }else {
        int ta=0,tb=0,f=0;
        for(j=3;j<i;j++){
            ta=ta*10+(str[j]-'0');
            tb=tb*10+(str[j]-'0');
        }
        for(j=i+1;j<n;j++)
            tb=tb*10+(str[j]-'0');
        a=tb-ta;
        b=fact[n-4]-fact[(i-3)];
    }
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,T;
    fact[0]=1;
    for(i=1;i<=9;i++)
        fact[i]=fact[i-1]*10;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        int a,b;
        solve(a,b);
        int g=gcd(a,b);
        //printf("a=%d b=%d\n",a,b);
        printf("%d/%d\n",a/g,b/g);
    }
    return 0;
}

