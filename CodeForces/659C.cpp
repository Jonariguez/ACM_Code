/****************
*PID:659c div2
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
int a[maxn];
vector<int> ans;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++) sc(a[i]);
        sort(a+1,a+n+1);
        a[n+1]=1e9+10;
        int res=0,now=1;
        int sum=0;
        ans.clear();
        i=1;
        while(m>0){
            if(now==a[i]){
                now++;i++;
            }else {
                if(m<now) break;
                res++;
                ans.push_back(now);
                m-=now;
                now++;
            }
        }
        pfn(res);
        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}





