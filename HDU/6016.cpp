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

const int maxn=100000+10;
const int MOD=1e9+7;

struct pp{
    int a,b;
}s[maxn];

int da[maxn],db[maxn];

int main()
{
    int i,j,n,T,m,k;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        memset(da,0,sizeof(da));
        memset(db,0,sizeof(db));
        for(i=1;i<=k;i++){
            scanf("%d%d",&s[i].a,&s[i].b);
            da[s[i].a]++;
            db[s[i].b]++;
        }
        LL res=0;
        for(i=1;i<=k;i++){
            int ta=s[i].a,tb=s[i].b;
            res+=1LL*(da[ta]-1)*(db[tb]-1);
        }
        printf("%lld\n",res*2);
    }
    return 0;
}
