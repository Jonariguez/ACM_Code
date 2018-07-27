/****************
*ID:bc53
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int vis[maxn],n;
vector<int> mp[maxn];
int u[maxn],v[maxn],deg[maxn];

typedef struct UFSet{
    int par[maxn];
    void Init(){ for(int i=0;i<maxn;i++) par[i]=i; }
    int Find(int x){ return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[v]=u;
        return true;
    }
}UFSet;

bool check(){
    int i,cnt=0;
    for(i=1;i<=n;i++)
        if(deg[i]&1) cnt++;
    return cnt==2;
}

int main()
{
    int i,j,k,m,T,kcase=1;
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            printf("YES\n");
            continue;
        }
        UFSet uf;
        memset(deg,0,sizeof(deg));
        int cnt=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&u[i],&v[i]);
            if(u[i]==v[i]){
                cnt++;
                continue;
            }
            deg[u[i]]++;deg[v[i]]++;
        }
        if(cnt>=2 || (cnt==1 && !check())){
            printf("NO\n");
            continue;
        }
        int yes=0;
        for(i=0;i<n;i++){
            deg[u[i]]--;deg[v[i]]--;
            int cc=n;
            uf.Init();
            for(j=0;j<n;j++){
                if(j==i) continue;
                if(uf.Union(u[j],v[j]))
                    cc--;
            }
            if(cc==1 && check()){
                yes=1;break;
            }
            deg[u[i]]++;deg[v[i]]++;
        }

        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
