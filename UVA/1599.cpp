/****************
*PID:uva1599
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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

const int maxn=100000+10;
const int INF=200000000;
int n,m,d[maxn],nxt[maxn],color[maxn],cc[maxn];
struct Edge{
    int from,to,col;
    bool operator < (const Edge &r) const {
        return col>r.col;
    }
};

struct Node{
    int u,D;
    bool operator < (const Node &r) const {
        return D>r.D;
    }
};

vector<Edge> con[maxn];

void Init(){
    for(int i=0;i<=n;i++)
        con[i].clear();
}

Edge z;

void add(int u,int v,int c){
    z.to=v;z.col=c;
    con[u].push_back(z);
}

void solve(){
    int i,j;
    for(i=0;i<=n;i++)
        d[i]=INF;
    d[n]=0;
    priority_queue<Node> que;
    Node u;
    u.u=n;u.D=0;
    que.push(u);
    while(!que.empty()){
        u=que.top();que.pop();
        if(u.u==1) return ;
        int last=-1;
        for(i=0;i<con[u.u].size();i++){
            Edge &e=con[u.u][i];
            int v=e.to;
            bool yes=false;
            if(d[v]>=d[u.u]+1){
                if(d[v]>d[u.u]+1)
                    yes=true;
                d[v]=d[u.u]+1;
                if((last==-1 || last>=e.col) && (cc[v]==0 || cc[v]>=e.col)){
                    nxt[v]=u.v;
                    color[u.u]=e.col;
                    last=e.col;
                }
                if(yes){
                    Node t;
                    t.u=v;t.D=d[v];
                    que.push(t);
                }
            }
        }
    }
}

int res[maxn];

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        int a,b,c;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(a==b) continue;
            add(a,b,c);add(b,a,c);
        }
        memset(cc,0,sizeof(cc));
        solve();
        int now=n,idx=0;
        while(now>1){
            res[idx++]=color[now];
            if(idx>100000) break;
            now=nxt[now];
        }
        printf("%d\n",d[1]);
        for(i=idx-1;i>=0;i--)
            printf("%d%c",res[i]," \n"[i==0]);
    }
    return 0;
}



