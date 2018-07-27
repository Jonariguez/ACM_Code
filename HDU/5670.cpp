/****************
*PID:hdu5670
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
LL bit[100];
char str[4]="RGB";

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        LL n,m;
        scanf("%I64d%I64d",&m,&n);
        LL cnt=0;
        while(n){
            bit[++cnt]=n%3;
            n/=3;
        }
        if(cnt<m){
            for(LL i=cnt;i<m;i++)
                printf("R");
        }
        for(LL i=min(m,cnt);i>=1;i--)
            printf("%c",str[bit[i]]);
        puts("");
    }
    return 0;
}




