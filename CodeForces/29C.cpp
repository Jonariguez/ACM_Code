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
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+10;
const int MOD=1e9+7;

int par[maxn];
int a[maxn],s[maxn],d[maxn][maxn];  //s[i]:第i个集合的元素个数 d[][]是集合数组
bitset<100001> b[1001],c,c2;

int Find(int x){
    return x==par[x]?x:par[x]=Find(par[x]);
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) par[i]=i;
    for(i=1;i<=n;i++){
        sc(a[i]);
        d[i][++s[i]]=a[i];
        b[i][a[i]]=1;
        b[i][0]=1;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int o;
        scanf("%d",&o);
        if(o==1){
            int x,y;
            scanf("%d%d",&x,&y);
            if(Find(x)==Find(y)) continue;
            x=Find(x);y=Find(y);
            if(s[x]<s[y]) swap(x,y);
            for(i=1;i<=s[y];i++){
                c2=b[x]<<d[y][i];
                b[x]|=c2;
            }
            for(i=1;i<=s[y];i++) d[x][++s[x]]=d[y][i];
            par[y]=x;
        }else {
            int x;
            scanf("%d",&x);
            x=Find(x);
            printf("%d\n",b[x].count());
        }
    }
    return 0;
}


