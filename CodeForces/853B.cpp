/****************
*PID:
*Auth:Jonariguez
*****************
in[i]:从第1天到第i天，全部的人都来到0城需要的最小花费
out[i]:从第i天到最后一天，全部的人都回到原位需要的最小花费
for一遍找到in[i]+out[i+k+1]的最小值即可
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

struct node{
    int f,t,c;
}s[maxn];

int cmp(const node &x,const node &y){
}

vector<node> vec[1000005];

LL in[1000005],out[1000005];
int vis[maxn];

int main()
{
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int mx=0;
    for(i=1;i<=m;i++){
        int d;
        scanf("%d%d%d%d",&d,&s[i].f,&s[i].t,&s[i].c);
        vec[d].push_back((node){s[i].f,s[i].t,s[i].c});
        mx=max(mx,d);
    }
    for(i=1;i<=n;i++)
        vis[i]=MOD;
    for(i=0;i<=mx+1;i++)
        in[i]=out[i]=100000000000000000LL;
    int cnt=0,l=-1,r=-1;
    LL sum=0;
    for(i=1;i<=mx;i++){
        in[i]=in[i-1];
        if(vec[i].size()==0){
            in[i]=in[i-1];continue;
        }
        for(j=0;j<vec[i].size();j++){
            if(vec[i][j].t) continue;
            if(vis[vec[i][j].f]>vec[i][j].c){
                if(vis[vec[i][j].f]!=MOD){
                    sum-=vis[vec[i][j].f]-vec[i][j].c;
                }else {
                    cnt++;
                    sum+=vec[i][j].c;
                }
                vis[vec[i][j].f]=vec[i][j].c;
            }
            if(cnt==n){
                if(l==-1) l=i;
                in[i]=sum;
            }
        }
    }
    cnt=0;
    sum=0;
    for(i=1;i<=n;i++)
        vis[i]=MOD;
    for(i=mx;i>=1;i--){
        out[i]=out[i+1];
        if(vec[i].size()==0){
            out[i]=out[i+1];continue;
        }
        for(j=0;j<vec[i].size();j++){
            if(vec[i][j].f) continue;
            if(vis[vec[i][j].t]>vec[i][j].c){
                if(vis[vec[i][j].t]!=MOD){
                    sum-=vis[vec[i][j].t]-vec[i][j].c;
                }else {
                    cnt++;
                    sum+=vec[i][j].c;
                }
                vis[vec[i][j].t]=vec[i][j].c;
            }
            if(cnt==n){
                if(r==-1) r=i;
                out[i]=sum;
            }
        }
    }
    if(r<0 || l<0 || r-l<=k){
        puts("-1");return 0;
    }
    LL res=100000000000000LL;
    for(i=l;i+k+1<=r;i++){
        res=min(res,in[i]+out[i+k+1]);
    }
    printf("%I64d\n",res);
    return 0;
}


