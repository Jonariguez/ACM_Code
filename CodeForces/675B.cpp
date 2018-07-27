/****************
*PID:675b div2
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

int main()
{
    int i,j,n,a,b,c,d;
    while(scanf("%d%d%d%d%d",&n,&a,&b,&c,&d)!=EOF){
      //  if(n==1){
      //      puts("1");
      //      continue;
      //  }
        int A=a+b,B=a+c,C=b+d,D=c+d;
        int temp1=max(max(A,B),max(C,D));
        int temp2=min(min(A,B),min(C,D));
        LL res=0;
        for(i=1;i<=n;i++)
            res+=max(0,n-(temp1-temp2));
        printf("%I64d\n",res);
    }
    return 0;
}


