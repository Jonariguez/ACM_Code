/****************
*PID:zoj3715
*Auth:Jonariguez
*****************
枚举最后得票数，
一开始是二分得票数了，不知道为啥错。(事实证明票数
不具有单调性，即最后得票数越少不见得越好)
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

const int maxn=100+10;
const int INF=1e8;
int n,m,choose,tot,vis[maxn],vis2[maxn],vis3[maxn];

struct node{
    int id,vote,c;
    bool operator < (const node &r) const {
        return c>r.c;
    }
}s[maxn];

bool C(int Mid,int &res){
    int i,now=vis[1];
    res=0;
    priority_queue<node> que[maxn];
    priority_queue<node> pq;
    memset(vis3,0,sizeof(vis3));
    for(i=1;i<=n;i++)
        vis3[i]=vis[i];
    for(i=1;i<=m;i++)
        que[s[i].vote].push(s[i]);
    memset(vis2,0,sizeof(vis2));
    for(i=2;i<=n;i++){
        while(que[i].size()>=Mid){
            node u=que[i].top();que[i].pop();
            vis2[u.id]=1;
            now++;
            res+=u.c;
        }
    }
    if(now>Mid) return false;
    for(i=1;i<=m;i++)
        if(vis2[i]==0)
            pq.push(s[i]);
    while(!pq.empty() && now<Mid){
        node u=pq.top();pq.pop();
        res+=u.c;now++;
    }
    return now==Mid;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<n;i++)
            sc(s[i].vote);
        for(i=1;i<n;i++)
            sc(s[i].c);
        memset(vis,0,sizeof(vis));
        m=0;
        for(i=1;i<n;i++){
            vis[s[i].vote]++;
            if(s[i].vote==1) continue;
            s[++m]=s[i];
            s[m].id=m;
        }
        choose=-1;
        for(i=2;i<=n;i++)
            if(choose==-1 || vis[choose]>vis[i]) choose=i;
        vis[choose]++;
        for(i=2;i<=n;i++)
            if(vis[i]>=vis[1]) break;
        if(i>n){
            printf("0\n");continue;
        }
        int res=INF,ans;
        for(i=max(1,vis[1]);i<n;i++){
            if(C(i,ans)){
                res=min(res,ans);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}



