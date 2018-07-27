/****************
*PID:uva10125
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

const int maxn=1000+10;
const int hashsize=1e7+3;
int sum[maxn][maxn],a[maxn];
int head[hashsize],nxt[maxn*maxn],cnt;

struct node{
    int sum;
    int x,y;
}st[maxn*maxn];

void Init(){
    memset(head,-1,sizeof(head));
    cnt=0;
}

int getHash(int sum){
    int h=sum&0x7fffffff;
    return h%hashsize;
}

void Insert(int sum){
    int h=getHash(sum);
    nxt[cnt]=head[h];
    head[h]=cnt;
}

bool Find(int sum,int i,int j){
    int h=getHash(sum);
    int v;
    for(v=head[h];v!=-1;v=nxt[v]){
        if(st[v].sum==sum && st[v].x!=i && st[v].x!=j && st[v].y!=i && st[v].y!=j) return true;
    }
    return false;
}

bool solve(int n,int &ans){
    int i,j;
    for(i=n;i>=1;i--){
        for(j=1;j<=n;j++){
            if(i==j) continue;
            if(Find(a[i]-a[j],i,j)){
                ans=a[i];return true;
            }
        }
    }
    return false;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        Init();
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                st[cnt].sum=a[i]+a[j];st[cnt].x=i;st[cnt].y=j;
                Insert(st[cnt].sum);
                cnt++;
            }
        }
        int res;
        if(solve(n,res))
            printf("%d\n",res);
        else puts("no solution");
    }
    return 0;
}





