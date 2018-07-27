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

const int maxn=1000+10;
const int MOD=1e9+7;

int a[maxn];
int head[10000],vv[10000],nxt[10000],wei[10000],e;

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v,int id){
    vv[e]=id;wei[e]=v;nxt[e]=head[u];head[u]=e++;
}

void Insert(int v,int id){
    int t=v%10000;
    add(t,v,id);
}

int Find(int v){
    int t=v%10000;
    if(head[t]==0) return 0;
    for(int i=head[t];i;i=nxt[i]){
        int V=vv[i],ww=wei[i];
        if(ww==v) return V;
    }
    return 0;
}

int main()
{
    int i,j,n,sum;
    while(scanf("%d%d",&n,&sum)!=EOF){
        Init();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            Insert(a[i],i);
        }
        int yes=0;
        for(i=1;i<=n && !yes;i++){
            for(j=i+1;j<=n && !yes;j++){
                if(j==i) continue;
                int t=a[i]+a[j];
                if(t>=sum) continue;
                int temp=Find(sum-t);
                if(temp && temp!=i && temp!=j){
                    yes=1;break;
                }
            }
        }
        if(yes)
            puts("YES");
        else puts("NO");
    }
    return 0;
}





