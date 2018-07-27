/****************
*PID:poj3259
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
const int maxm=2500+5;
const int INF=1e9;
int head[maxn],vv[maxm*2+200],wei[maxm*2+200],nxt[maxm*2+200],d[maxn],e,n,m,w;

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

bool bellman_ford(){
    int i,j,k,yes;
    for(i=1;i<=n;i++) d[i]=INF;
    d[1]=0;
    for(k=1;k<=n-1;k++){
        yes=0;
        for(i=1;i<=n;i++){
            for(j=head[i];j;j=nxt[j]){
                int v=vv[j],w=wei[j];
                if(d[i]<INF && d[v]>d[i]+w){
                    d[v]=d[i]+w;yes=1;
                }
            }
        }
        if(!yes) break;
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j;j=nxt[j]){
            int v=vv[j],w=wei[j];
            if(d[i]<INF && d[v]>d[i]+w)
                return false;
        }
    }
    return true;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&w);
        Init();
        int a,b,c;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);add(b,a,c);
        }
        for(i=0;i<w;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,-c);
        }
        if(bellman_ford())
            puts("NO");
        else puts("YES");
    }
    return 0;
}

