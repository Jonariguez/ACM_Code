/****************
*PID:
*Auth:Jonariguez
*****************

"������һ�£���Ϊÿ�ζ���Ҫ֪����ǰ����-1����Ϣ��
������ö�ٿ�����ö��λ�������ƣ�ͨ������ÿ��ֻ�轨һ���߶���"
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

const int maxn=35000+10;
const int MOD=1e9+7;

int a[maxn],vis[maxn],last[maxn];
int dp[maxn];

typedef struct Seg{
    int sum[maxn*4],add[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void pushDown(int k){
        if(add[k]){
            add[k*2]+=add[k];
            add[k*2+1]+=add[k];
            sum[k*2]+=add[k];
            sum[k*2+1]+=add[k];
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        add[k]=0;
        sum[k]=0;
        if(l==r){
            sum[k]=dp[l];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void update(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            sum[k]+=v;add[k]+=v;
            return ;
        }
        pushDown(k);
        int m=(l+r)/2;
        if(a<=m)
            update(a,b,v,lson);
        if(b>m)
            update(a,b,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b){
            return sum[k];
        }
        pushDown(k);
        int m=(l+r)/2,res=-1;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    memset(vis,0,sizeof(vis));
    dp[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        last[i]=vis[a[i]];
        if(!vis[a[i]]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
        vis[a[i]]=i;
    }
    for(i=2;i<=k;i++){
        tree.build(1,1,n);
        for(j=i;j<=n;j++){
            //ע�⣬�Ǵ�last[j]~j-1��������last[j]+1~j,��һ���ύ��ע���Ǵ�ġ�����ԭ�����
            tree.update(last[j],j-1,1,1,1,n);   //��dp[i-1][]�Ļ����ϣ��ѵ�j������Ӱ���ȼӵ�֮ǰ��״̬����ȡ���ž���
            dp[j]=tree.ask(1,j,1,1,n);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}

//��Ȼ��j������Ӱ�쵽last[j]+1����������Ҫ����dp[i-1][x]+val[x+1,j]�����ֵ
//���ԣ�����xȡ��last[j]��x+1Ҳ��last[j]+1���������һ���ܹ�+1
//!!!!˵���˾��ǣ��߶����е�����last[j]~j-1����ʵ�Ƕ�Ӧ״̬ת�Ʒ����е�x������

