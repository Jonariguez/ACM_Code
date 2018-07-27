/****************
*PID:
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

const int maxn=200000+10;
const int MOD=1e9+7;

int par[maxn],rel[maxn],n,IDcnt;
map<string,int> mp;

int ID(string st){
    if(!mp.count(st))
        return mp[st]=++IDcnt;
    return mp[st];
}

void Init(){
    mp.clear();
    IDcnt=0;
    for(int i=1;i<=n;i++)
        par[i]=i;
    memset(rel,0,sizeof(rel));
}

int Find(int u){
    if(u==par[u])
        return u;
    int temp=Find(par[u]);
    rel[u]^=rel[par[u]];
    return par[u]=temp;
}

int ask(int u,int v){
   // printf("u=%d v=%d\n",u,v);
    int fu=Find(u),fv=Find(v);
   // printf("fu=%d\n",fu);
    if(fu==fv){
       // printf("ru=%d rv=%d\n",rel[u],rel[v]);
        return (rel[u]^rel[v]);
    }
    return 2;
}

void Union(int u,int v,int r){
    int fu=Find(u),fv=Find(v);
    if(!r){
        rel[fu]=rel[u]^rel[v];
        par[fu]=fv;
    }else {
        rel[fu]=(rel[u]^rel[v])^1;
        par[fu]=fv;
    }
}


int main()
{
    int i,j,m,q,a,b,t;
    scanf("%d%d%d",&n,&m,&q);
    Init();
    string str,stra,strb;
    for(i=1;i<=n;i++){
        cin>>str;
        ID(str);
    }
    for(i=1;i<=m;i++){
        cin>>t>>stra>>strb;
        a=ID(stra);
        b=ID(strb);
        int temp=ask(a,b);
        if(temp==2){
            Union(a,b,t-1);
            puts("YES");
        }else {
            if(temp==t-1)
                puts("YES");
            else puts("NO");
        }
    }
    while(q--){
        cin>>stra>>strb;
        a=ID(stra);
        b=ID(strb);
        printf("%d\n",ask(a,b)+1);
    }
    return 0;
}
