/****************
*PID:650d div1
*Auth:Jonariguez
*****************
dp1[i]表示从1开始到第i个位置的最长上升子序列长度，
dp2[i]表示从i开始到第n个位置的最长上升子序列长度。
dp3[i]表示第i个询问的那个位置从1开始到第x个位置的最长上升子序列长度，
dp4[i]表示第i个询问的那个位置从x开始到第n个位置的最长上升子序列长度，
x为对应询问中的修改位置。
ans=max(LIS,dp3[i]+dp[4]-1);
如果ans是关键点，上式中LIS取lIS-1，注释有解释。
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

const int maxn=400000+10;
int dp1[maxn],dp2[maxn],dp3[maxn],dp4[maxn],a[maxn],cnt[maxn];
vector<int> P;
vector<pair<int,int> > Q[maxn];
map<int,int> Hash;

struct Command{
    int x,y;
   // bool operator < (const Command &r) const {
  //      x<r.x;
  //  }
}s[maxn];

struct Segment{
    int sum[maxn*8];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=0;
        if(l==r) return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=max(sum[k],v);return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,lson);
        else update(p,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a>b) return 0;
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=0;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        return res;
    }
}tree;  //线段树用来返回以某个值结尾的LIS的长度。(当然可以返回来用，求以某个值开始的LIS)

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        P.clear();Hash.clear();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            P.push_back(a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&s[i].x,&s[i].y);
            P.push_back(s[i].y);
            Q[i].clear();
        }
        sort(P.begin(),P.end());
        P.erase(unique(P.begin(),P.end()),P.end());
        for(i=0;i<P.size();i++)
            Hash[P[i]]=i+1;
        for(i=1;i<=n;i++)
            a[i]=Hash[a[i]];
        for(i=1;i<=m;i++){
            s[i].y=Hash[s[i].y];
            Q[s[i].x].push_back(make_pair(i,s[i].y));
        }
        int N=P.size();
        tree.build(1,1,N);
        for(i=1;i<=n;i++){
            dp1[i]=tree.ask(1,a[i]-1,1,1,N)+1;
            for(j=0;j<Q[i].size();j++){ //更新所有关于第i个位置的询问
                int id=Q[i][j].first;       //所在询问的编号，属于[1,m]
                int v=Q[i][j].second;
                dp3[id]=tree.ask(1,v-1,1,1,N)+1;
            }
            tree.update(a[i],dp1[i],1,1,N);
        }
      //  reverse(a+1,a+n+1);
        tree.build(1,1,N);
        for(i=n;i>=1;i--){
            dp2[i]=tree.ask(a[i]+1,N,1,1,N)+1;
            for(j=0;j<Q[i].size();j++){
                int id=Q[i][j].first;
                int v=Q[i][j].second;
                dp4[id]=tree.ask(v+1,N,1,1,N)+1;
            }
            tree.update(a[i],dp2[i],1,1,N);
        }
        memset(cnt,0,sizeof(cnt));
        int LIS=0;
        for(i=1;i<=n;i++)
            LIS=max(LIS,dp1[i]);
        for(i=1;i<=n;i++)       //计算每个[1,LIS]之间的长度是否唯一，如a=1 2 2 3 dp[2]=dp[3]=2,那么LIS=3且不唯一
            if(dp1[i]+dp2[i]==LIS+1)     //即cnt[ dp[2]=dp[3]=2 ]=2，故长度为2的LIS的不唯一，那么a[2]和a[3]都不是
                cnt[dp1[i]]++;          //关键点,即修改2位置或者3位置都不会影响LIS的长度。
        for(i=1;i<=m;i++){
            int ans=LIS;
            int x=s[i].x;
            if(dp1[x]+dp2[x]==LIS+1 && cnt[dp1[x]]==1) ans--;   //因为是关键位置，所以改动的话可能影响LIS，故要
            ans=max(ans,dp3[i]+dp4[i]-1);  //-1,那么万一即便改动一样不影响LIS的长度怎么办，这个没问题，
            pfn(ans);                           //因为会用ans=max(ans,dp3[i]+dp4[i]-1);更新过来.
        }
    }
    return 0;
}


