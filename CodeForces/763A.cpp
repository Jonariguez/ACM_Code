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

int a[maxn],b[maxn],c[maxn],cnt[maxn];
vector<int> con[maxn];

bool dfs(int u,int pa){
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        if(pa!=0 && c[v]!=c[u]) return false;
        if(!dfs(v,u)) return false;
    }
    return true;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<n;++i)
            scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            con[i].clear();
        }
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<n;i++){
            if(c[a[i]]!=c[b[i]]){
                cnt[a[i]]++;cnt[b[i]]++;
            }
            con[a[i]].push_back(b[i]);
            con[b[i]].push_back(a[i]);
        }
        int c1=0,c2=0,p=0;
        for(i=1;i<=n;i++){
            if(cnt[i]>=2){
                c2++;p=i;
            }
            if(cnt[i]==1) c1++;
        }
        if(c2>=2){
            puts("NO");
            continue;
        }
        if(c2==1){
            if(dfs(p,0))
                printf("YES\n%d\n",p);
            else puts("NO");
        }
        if(c2==0){
            for(p=1;p<=n;p++)
                if(cnt[p]) break;
            if(p>n){
                printf("YES\n1\n");continue;
            }
            if(dfs(p,0))
                printf("YES\n%d\n",p);
            else puts("NO");
        }
    }
    return 0;
}


