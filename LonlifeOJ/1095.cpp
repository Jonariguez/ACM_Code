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
const LL MM=10000000000LL;

LL cal(int n,int b){
    LL res=0;
    for(int i=b-1;i>=0;i--){
        if((n>>i)&1)
            res=res*10+6;
        else res=res*10+1;
    }
    return res;
}

vector<LL> vec,v;

void dfs(LL now){
    for(int i=1;i<vec.size();i++){
        if(now*vec[i]>MM) return ;
        v.push_back(now*vec[i]);
        dfs(now*vec[i]);
    }
}

int main()
{
    int i,j;
    vec.clear();
    for(j=1;j<=10;j++){
        for(i=0;i<(1<<j);i++){
           // printf("%lld\n",cal(i,j));
            vec.push_back(cal(i,j));
        }
    }
    sort(vec.begin(),vec.end());
    dfs(1LL);
    for(i=0;i<vec.size();i++)
        v.push_back(vec[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int T;
    LL L,R;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&L,&R);
        printf("%d\n",(upper_bound(v.begin(),v.end(),R)-v.begin())-(upper_bound(v.begin(),v.end(),L-1)-v.begin()));
    }
    return 0;
}

