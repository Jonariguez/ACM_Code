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

map<char,char> mp;

void solve(string &a,string &b){
    int i;
    for(i=0;i<a.length();i++)
        mp[a[i]]=b[i];
}

char str[maxn];

int main()
{
    int i,j,n,m;
    string a,b;
    a="IuVEJxTXs";
    b="vpVZzBNtL";
    solve(a,b);
    a="CARS";
    b="Unil";
    solve(a,b);
    a="cars";
    b="EPFL";
    solve(a,b);
    a="IuVEJxTXs";
    b="vpVZzBNtL";
    solve(a,b);
    a=" UvOHhng yZKfAYmaqolM";
    b=" SCubWma ocIYneAPqxDs";
    solve(a,b);
    a="NtGQibw djPrCpek FWzL";
    b="hRkMGgJ fHrFUQTj XOwd";
    solve(a,b);
    a="aySBaPyb RM gzYMynY";
    b="PolyProg is awesome";
    solve(a,b);
    mp['D']='K';

    int x;
    scanf("%d",&x);
    getchar();
    gets(str+1);
    n=strlen(str+1);
    for(i=1;i<=n;i++)
        printf("%c",mp[str[i]]);
    puts("");
    return 0;
}


