/****************
*PID:443a div2
*Auth:Jonariguez
*****************
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

const int maxn=100000+10;

char str[22];
int vis[30];

int main()
{
    int i,j,n,res=0;
    scanf("%s",str);
    if(str[0]=='{' && str[1]=='}')
        {
            puts("0");return 0;
        }
    n=strlen(str);
    if(n>2 && str[0]=='{' && str[2]=='}'){
        puts("1");return 0;
    }
    if(vis[str[1]-'a']==0) res++;
    vis[str[1]-'a']=1;
    while(scanf("%s",str)){
        if(vis[str[0]-'a']==0)
            res++;
        vis[str[0]-'a']=1;
        if(str[1]=='}') break;
}
pfn(res);
return 0;
}



