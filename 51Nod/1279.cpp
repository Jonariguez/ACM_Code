/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

vector<int> vec;
int a[maxn],b[maxn],p[maxn];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        sc(a[i]);
        vec.PB(a[i]);
    }
    for(i=1;i<=m;i++){
        sc(b[i]);
        vec.PB(b[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(i=1;i<=vec.size();i++) p[i]=MOD;
    for(i=n;i>=1;i--){
        a[i]=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
        p[a[i]]=i;
    }
    for(i=m;i>=1;i--){
        b[i]=upper_bound(vec.begin(),vec.end(),b[i])-vec.begin();
    }
    for(i=2;i<=vec.size();i++)
        p[i]=min(p[i],p[i-1]);
    int res=0,now=n;
    for(i=1;i<=m && now;i++){
        if(b[i]==1){
            res++;now--;
        }else {
            int t=min(p[b[i]-1]-1,now);
            if(t){
                res++;now=t-1;
            }else break;
        }
    }
    pfn(res);
    return 0;
}


