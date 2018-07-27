/****************
*PID:437b div2
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
int bit[maxn],a[maxn];
vector<int> res;

int lowbit(int x){
    return x&(-x);
}

struct pp{
    int v,id;
}s[maxn];

int cmp(pp x,pp y){
    return x.v>y.v;
}

int main()
{
    int i,j,n,m;
    for(i=1;i<=100000;i++)
        bit[i]=lowbit(i);
    while(scanf("%d%d",&n,&m)!=EOF){
        LL sum=0;
        for(i=1;i<=m;i++){
            s[i].v=bit[i];
            s[i].id=i;
            sum+=bit[i];
        }
        if(sum<(LL)n){
            puts("-1");continue;
        }
        sort(s+1,s+m+1,cmp);
        res.clear();
        for(i=1;i<=m;i++){
            if(n>=s[i].v){
                res.push_back(s[i].id);
                n-=s[i].v;
            }
            if(n==0) break;
        }
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
            printf("%d%c",res[i]," \n"[i==res.size()-1]);
    }
    return 0;
}



