/****************
*PID:
*Auth:Jonariguez
*****************
贪心，如果不能找到很好的贪心策略时，就先按
目前来贪心，然后不够的话再回去调整。
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

int a[maxn],b[maxn],c[maxn],vis[maxn];
struct node{
    int v,id;
    bool operator < (const node &r) const {
        if(v==r.v)
            return id>r.id;
        return v<r.v;
    }
};

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        c[i]=a[b[i]];
    }
    int sum1=0,sum2=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i+=2){
        if(i==n){
            vis[i]=1;break;
        }
        j=i+1;
        if(c[j]>c[i]){
            vis[j]=1;
            int p,v=-1;
            for(p=1;p<i;p++){
                if(!vis[p]) continue;
                if(v==-1 || c[v]>c[p])
                    v=p;
            }
            if(v!=-1 && c[v]<c[i])
                swap(vis[i],vis[v]);
        }else {
            vis[i]=1;
            int p,v=-1;
            for(p=1;p<i;p++){
                if(!vis[p]) continue;
                if(v==-1 || c[v]>c[p])
                    v=p;
            }
            if(v!=-1 && c[v]<c[j])
                swap(vis[j],vis[v]);
        }
    }
    for(i=1;i<=n;i++)
        if(vis[i]) sum1+=c[i];
        else sum2+=c[i];
    printf("%d\n",sum1-sum2);
    return 0;
}

