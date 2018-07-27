/****************
*PID:uva11082
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

const int maxn=50+10;
const int MOD=1e9+7;
const int INF=1e9;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];

    void Init(int n){
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void addEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Maxflow(int s,int t){
        int flow=0;
        for(;;){
            memset(a,0,sizeof(a));
            queue<int> que;
            que.push(s);
            a[s]=INF;
            while(!que.empty()){
                int x=que.front();que.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e=edges[G[x][i]];
                    if(!a[e.to] && e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        que.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};

EdmondsKarp g;

int id[maxn][maxn];

int main()
{
    int i,j,R,C,T,kcase=0;
    scanf("%d",&T);
    for(kcase=1;kcase<=T;kcase++){
        scanf("%d%d",&R,&C);
        g.Init(R+C+2);
        int last=0,v;
        for(i=1;i<=R;i++){
            scanf("%d",&v);
            g.addEdge(0,i,v-last-C);
            last=v;
        }
        last=0;
        for(i=1;i<=C;i++){
            scanf("%d",&v);
            g.addEdge(R+i,R+C+1,v-last-R);
            last=v;
        }
        for(i=1;i<=R;i++){
            for(j=1;j<=C;j++){
                g.addEdge(i,R+j,19);
                id[i][j]=g.edges.size()-2;  //Ìø¹ý·´Ïò±ß
            }
        }
        g.Maxflow(0,R+C+1);
        printf("Matrix %d\n",kcase);
        for(i=1;i<=R;i++){
            for(j=1;j<=C;j++)
                printf("%d ",g.edges[id[i][j]].flow+1);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}




