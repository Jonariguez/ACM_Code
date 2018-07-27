/****************
*PID:650d div1
*Auth:Jonariguez
*****************
dp1[i]��ʾ��1��ʼ����i��λ�õ�����������г��ȣ�
dp2[i]��ʾ��i��ʼ����n��λ�õ�����������г��ȡ�
dp3[i]��ʾ��i��ѯ�ʵ��Ǹ�λ�ô�1��ʼ����x��λ�õ�����������г��ȣ�
dp4[i]��ʾ��i��ѯ�ʵ��Ǹ�λ�ô�x��ʼ����n��λ�õ�����������г��ȣ�
xΪ��Ӧѯ���е��޸�λ�á�
ans=max(LIS,dp3[i]+dp[4]-1);
���ans�ǹؼ��㣬��ʽ��LISȡlIS-1��ע���н��͡�
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
}tree;  //�߶�������������ĳ��ֵ��β��LIS�ĳ��ȡ�(��Ȼ���Է������ã�����ĳ��ֵ��ʼ��LIS)

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
            for(j=0;j<Q[i].size();j++){ //�������й��ڵ�i��λ�õ�ѯ��
                int id=Q[i][j].first;       //����ѯ�ʵı�ţ�����[1,m]
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
        for(i=1;i<=n;i++)       //����ÿ��[1,LIS]֮��ĳ����Ƿ�Ψһ����a=1 2 2 3 dp[2]=dp[3]=2,��ôLIS=3�Ҳ�Ψһ
            if(dp1[i]+dp2[i]==LIS+1)     //��cnt[ dp[2]=dp[3]=2 ]=2���ʳ���Ϊ2��LIS�Ĳ�Ψһ����ôa[2]��a[3]������
                cnt[dp1[i]]++;          //�ؼ���,���޸�2λ�û���3λ�ö�����Ӱ��LIS�ĳ��ȡ�
        for(i=1;i<=m;i++){
            int ans=LIS;
            int x=s[i].x;
            if(dp1[x]+dp2[x]==LIS+1 && cnt[dp1[x]]==1) ans--;   //��Ϊ�ǹؼ�λ�ã����ԸĶ��Ļ�����Ӱ��LIS����Ҫ
            ans=max(ans,dp3[i]+dp4[i]-1);  //-1,��ô��һ����Ķ�һ����Ӱ��LIS�ĳ�����ô�죬���û���⣬
            pfn(ans);                           //��Ϊ����ans=max(ans,dp3[i]+dp4[i]-1);���¹���.
        }
    }
    return 0;
}


