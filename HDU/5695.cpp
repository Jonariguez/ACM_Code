/****************
*PID:hdu5695
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
vector<int> con[maxn];
int n,d[maxn];

void Init(){
    for(int i=0;i<=n;i++)
        con[i].clear();
    memset(d,0,sizeof(d));
}

LL solve(){
    int i,j;
    LL ans=0,now=n;
    priority_queue<int> que;
    for(i=1;i<=n;i++)
        if(d[i]==0)
            que.push(i);
    while(!que.empty()){
        int u=que.top();que.pop();
        now=min(now,(LL)u);
        ans+=now;
        for(i=0;i<con[u].size();i++){
            int v=con[u][i];
            d[v]--;
            if(d[v]==0)
                que.push(v);
        }
    }
    return ans;
}


int main()
{
    int i,j,T,kcase=1,m;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        for(i=1;i<=m;i++){
            int a,b;
            sc(a);sc(b);
            con[a].push_back(b);
            d[b]++;
        }
        printf("%I64d\n",solve());
    }return 0;
}



