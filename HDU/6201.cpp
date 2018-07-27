/****************
*PID:hdu6201
*Auth:Jonariguez
*****************
buy[u]������uΪ���������е�ĳһ������Ϊ��㣬���䵽u����ʣ��ֵ�����ֵ��
sell[u]:����uΪ���������е�ĳһ������Ϊ���㣬���䵽u����ʣ��ֵ�����ֵ��
��Ϊ��u��v�ʹ�v��u���ķѵļ�ֵ��һ���ģ�����sell[u]ά�����ӽڵ㵽���ڵ��
ά���Ӹ��ڵ㵽�ӽڵ���һ���ġ�
����ÿһ����ȡbuy[u]+sell[u]�����ֵ��Ϊ��
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

const int maxn=100000+10;
const int MOD=1e9+7;

int p[maxn],buy[maxn],sell[maxn];
struct node{
    int to,d;
};
vector<node> vec[maxn];

LL res;

void dfs(int u,int pa){
    buy[u]=-p[u];sell[u]=p[u];
    if(vec[u].size()==1 && vec[u][0].to==pa){
        return ;
    }
    int i;
    for(i=0;i<vec[u].size();i++){
        int v=vec[u][i].to,w=vec[u][i].d;
        if(v==pa) continue;
        dfs(v,u);
        buy[u]=max(buy[u],buy[v]-w);
        sell[u]=max(sell[u],sell[v]-w);
    }
    res=max(res,1LL*buy[u]+sell[u]);
}


int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
            vec[i].clear();
        }
        for(i=1;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            vec[x].push_back((node){y,z});
            vec[y].push_back((node){x,z});
        }
        res=0;
        dfs(1,0);
        printf("%I64d\n",res);
    }
    return 0;
}

