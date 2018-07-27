/****************
*ID:uva
*Auth:Jonariguez
*****************
Å·À­µÀÂ·
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[1010];
typedef struct UFSet{
    int par[300];
    void init(){
        for(int i=0;i<300;i++) par[i]=i;
    }
    int findset(int x){
        return x==par[x]?x:par[x]=findset(par[x]);
    }
    bool Union(int u,int v){
        if((u=findset(u))==(v=findset(v))) return false;
        par[u]=v;
        return true;
    }
}UFSet;

UFSet ufset;
int vis[300],deg[300];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(deg,0,sizeof(deg));
        ufset.init();
        int cone_cnt=26;
        for(i=0;i<n;i++){
            scanf("%s",str);
            char c1=str[0],c2=str[strlen(str)-1];
            deg[c1]++;
            deg[c2]--;
            vis[c1]=vis[c2]=1;
            if(ufset.Union(c1,c2))
                cone_cnt--;
        }

        vector<int> d;
        for(int ch='a';ch<='z';ch++){
            if(!vis[ch]) cone_cnt--;
            else if(deg[ch]!=0)
                d.push_back(deg[ch]);
        }

        bool ok=false;
        if(cone_cnt==1 && (d.empty() || d.size()==2 && (d[0]==1 || d[0]==-1)))
            ok=true;
        if(ok)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
