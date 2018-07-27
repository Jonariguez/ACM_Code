/****************
*PID:zoj3261
*Auth:Jonariguez
*****************
考虑离线，将删掉的边删掉后建图更新答案，然后
逆序处理指令，遇到查询则记录答案，遇到删边则加边。

注意，为了区别边0 1和边1 0，统一用(小，大)表示
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
const int maxm=20000+10;
const int maxq=50000+10;
int vis[maxm],p[maxn],res[maxq],par[maxn],U[maxm],V[maxm],n,m,q;
map<pair<int,int>,int> mp;
char str[21];

struct command{
    int c,a,b;
}s[maxq];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void merge(int u,int v){
    int pu=find(u),pv=find(v);
    if(pu==pv) return ;
    if(p[pu]==p[pv]){
        if(pv<pu) par[pu]=pv;
        else par[pv]=pu;
    }else if(p[pu]<p[pv]){
        par[pu]=pv;
    }else par[pv]=pu;
}

int main()
{
    int i,j,k=0;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        if(k) printf("\n");
        k=1;
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
            par[i]=i;
        }
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a++;b++;
            U[i]=min(a,b);V[i]=max(a,b);
            mp[make_pair(U[i],V[i])]=i;
        }
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%s",str);
            if(str[0]=='d'){
                int a,b,A,B;
                scanf("%d%d",&a,&b);
                a++;b++;
                A=min(a,b);B=max(a,b);
                int id=mp[make_pair(A,B)];
                vis[mp[make_pair(A,B)]]=1;
                s[i].a=A;s[i].b=B;
                s[i].c=0;
            }else {
                int A;
                scanf("%d",&A);
                A++;
                s[i].a=A;s[i].c=1;
            }
        }
       // memset(res,-1,sizeof(res));
        for(i=1;i<=m;i++){
            if(vis[i]==1) continue;
            int u=U[i],v=V[i];
            merge(u,v);
        }
        for(i=q;i>=1;i--){
            if(s[i].c==1){
                if(p[find(s[i].a)]<=p[s[i].a])
                    res[i]=-1;
                else res[i]=find(s[i].a)-1;
            }else {
              //  int id=mp[make_pair(s[i].a,s[i].b)];
              //  int u=U[id],v=V[id];
                merge(s[i].a,s[i].b);
            }
        }
        for(i=1;i<=q;i++){
            if(s[i].c)
                printf("%d\n",res[i]);
        }
    }
    return 0;
}
