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

const int maxn=1023+10;
const int MOD=1e9+7;

int d[2][maxn];

int main()
{
    int i,j,n,k,x;
    while(scanf("%d%d%d",&n,&k,&x)!=EOF){
        int v;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++){
            scanf("%d",&v);
            d[0][v]++;
        }
        int cnt=0,f=1;
        while(k--){
            memset(d[f&1],0,sizeof(d[f&1]));
            cnt=0;
            for(i=0;i<=1023;i++){
                int c=d[f^1][i],t;
                if(cnt%2==0){
                    d[f][i^x]+=(t=(c+1)/2);
                    d[f][i]+=c-t;
                }else{
                    d[f][i]+=(t=(c+1)/2);
                    d[f][i^x]+=c-t;
                }
                cnt+=c;
            }
            f^=1;
        }
        f^=1;
        int res=1023;
        while(d[f][res]==0) res--;
        printf("%d ",res);
        res=0;
        while(d[f][res]==0) res++;
        printf("%d\n",res);
    }
    return 0;
}

