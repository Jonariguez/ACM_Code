/****************
*PID:327b div2
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

const int maxn=10000000+10;
bool vis[maxn];
vector<int> prime;

void table(){
    int i,j;
    for(i=2;i<=3000000;i++){
        if(!vis[i])
            prime.push_back(i);
        for(j=0;j<prime.size();j++){
            if(i*prime[j]>3000000) break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    int i,j,n,m;
    table();
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            printf("%d ",prime[i]);
        puts("");
    }
    return 0;
}



