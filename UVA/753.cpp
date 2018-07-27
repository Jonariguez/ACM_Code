/****************
*PID:uva753
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

const int maxn=400+10;
const int MOD=1e9+7;

vector<string> names;

int ID(const string &s){
    for(int i=0;i<names.size();i++)
        if(names[i]==s)
            return i;
    names.push_back(s);
    return names.size()-1;
}

int n,m,k;
int d[maxn][maxn];
int device[maxn];
int target[maxn];

const int INF=1000000000;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp{
    int n,m;            //顶点数和边数
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

    int MaxFlow(int s,int t){
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

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        names.clear();
        string s1,s2;
        for(i=1;i<=n;i++){
            cin>>s1;
            target[i]=ID(s1);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            cin>>s1>>s2;
            device[i]=ID(s2);
        }
        scanf("%d",&k);
        memset(d,0,sizeof(d));
        for(i=1;i<=k;i++){
            cin>>s1>>s2;
            d[ID(s1)][ID(s2)]=1;
        }
        int N=names.size();
        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    d[i][j]|=(d[i][k] && d[k][j]);

        g.Init(N+2);    //N是超级源，N+1是超级汇
        for(i=1;i<=n;i++)  //目标target，连超级汇
            g.addEdge(target[i],N+1,1);

        for(i=1;i<=m;i++)   //设备device，连超级源
            g.addEdge(N,device[i],1);

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(d[device[j]][target[i]])
                    g.addEdge(device[j],target[i],INF);
        int res=g.MaxFlow(N,N+1);
        printf("%d\n",m-res);
        if(T)
            puts("");
    }
    return 0;
}
