/****************
*PID:corc2016a
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
#define MEM(c) memset(c,0,sizeof(c))
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

int c[110][110];

int main()
{
    int i,j,n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        if(n>a*b){
            puts("-1");continue;
        }
        MEM(c);
        int odd=-1,even=0;
        for(i=1;i<=a;i++){
            for(j=1;j<=b;j++){
                if((i+j)%2==0){
                    odd+=2;
                    if(odd<=n) c[i][j]=odd;
                }else {
                    even+=2;
                    if(even<=n)
                        c[i][j]=even;
                }
            }
        }
        for(i=1;i<=a;i++)
            for(j=1;j<=b;j++)
                printf("%d%c",c[i][j]," \n"[j==b]);
    }
    return 0;
}



