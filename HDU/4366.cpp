/****************
*PID:hdu4366
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

const int maxn=50000+10;
const int MAGIC=250;        //¿éµÄ´óÐ¡
struct staff{
    int loy,abi,id;
    bool operator < (const staff &r) const {
        return abi<r.abi;
    }
}s[maxn];
int start[maxn],End[maxn],seq[maxn],maxx[maxn],right[maxn],dfs_clock,n;
vector<int> son[maxn];
vector<staff> block[maxn];

void Init(){
    for(i=0;i<=n;i++)
        son[i].clear();
    dfs_clock=0;
}

void add(int u,int v){
    son[u].push_back(v);
}

void dfs(int u){
    start[u]=++dfs_clock;
    seq[dfs_clock]=u;
    for(int i=0;i<son[u].size();i++){
        int v=son[u][i];
        dfs(v);
    }
    End[u]=dfs_clock;
}

void separate(){
    int i,j;
    for(i=1;i<=n;i++)
        b[(i-1)/MAGIC].push_back(s[i]);
    for(i=0;i<n;i++){
        if(b[i].size()<=1) break;
        sort(b[i].begin(),b[i].end());
        right[b[i].size()-1]=-1;
        right[b[i].size()-2]=b[i].size()-1;
        for(j=b[i].size()-1;j>=0;j--)
            right[j]=max(right[i]
    }







int main()
{
    int i,j,m,T;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        for(i=2;i<=n;i++){
            int a;
            scanf("%d%d%d",&a,&s[i].loy,&s[i].abi);
            s[i].id=i;
            a++;
            add(a,i);
        }
        dfs(1);
        separate();



