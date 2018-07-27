/****************
*PID:hdu5631
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;

struct pp{
    int x,y;
}s[maxn];

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

UFSet Set;

int main()
{
    int i,j,n,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<=n;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        LL res=0;
        int a,b;
        for(i=0;i<=n;i++){
            for(j=i;j<=n;j++){
                Set.Init();
               // int yes=1;
                for(k=0;k<=n;k++){
                    if(k==i || k==j) continue;
                    a=Set.Find(s[k].x);b=Set.Find(s[k].y);
                    Set.Union(a,b);
                }
                int cnt=0;
                for(k=1;k<=n;k++)
                    if(Set.Find(k)==k) cnt++;
                if(cnt==1) res++;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}


