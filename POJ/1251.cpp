/****************
*PID:poj1251
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=30;
int par[maxn],n,m;
map<char,int> mp;

struct Edge{
    char a,b;
    int w;
}s[80];

int cmp(const Edge &x,const Edge &y){
    return x.w<y.w;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

int main()
{
    int i,res,j;
    while(scanf("%d",&n),n){
        for(i=0;i<=n;i++) par[i]=i;
        m=0;
        mp.clear();
        int tot=(n+1)*n/2;
        char str[11];
        for(i=1;i<n;i++){
            scanf("%s",str);
            mp[str[0]]=i;
            tot-=(str[0]-'A')+1;
            int k=0,d;
            char c=str[0];
            scanf("%d",&k);
            while(k--){
                scanf("%s%d",str,&d);
                s[m].a=c;s[m].b=str[0];
                s[m++].w=d;
            }
        }
        sort(s,s+m,cmp);
        mp[(tot-1+'A')]=n;
        int cnt=0;
        res=0;
        for(i=0;i<m;i++){
            if(merge(mp[s[i].a],mp[s[i].b])){
                res+=s[i].w;
                if(++cnt==n-1) break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

