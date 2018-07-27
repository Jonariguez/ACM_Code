/****************
*PID:486d div2
*Auth:Jonariguez
*****************
ö���½磬����dp
���ȥ�أ��涨�ӱ��С������Ŵ��dp���磺
��1,2,3��Ȩֵ��ȣ����1��ʼ��dp�õ�{1},{1,2},{1,2,3}
��2��ʼ��dp�õ�{2},{2,3}(��������ű��Լ�С��1��)
��3��ʼ��dp�õ�{3}������1��2����
�����Ϳ���ȥ���ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+5;
const int mod=1000000007;

int head[maxn],vv[maxn*2],nxt[maxn*2],a[maxn],e,d,n;
LL dp[maxn];

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int w,int ori){
    if((a[u]>w && a[u]-w<=d) || a[u]==w && ori<=u){
        dp[u]=1;
        int i;
        for(i=head[u];i;i=nxt[i]){
            int v=vv[i];
            if(v==pa) continue;
            dfs(v,u,w,ori);
            dp[u]*=(dp[v]+1);
            dp[u]%=mod;
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&d,&n)!=EOF){
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(head,0,sizeof(head));
        e=1;
        for(i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        LL res=0;
        for(i=1;i<=n;i++){
            memset(dp,0,sizeof(dp));
            dfs(i,-1,a[i],i);
            res+=dp[i];
           // printf("dp=%I64d\n",dp[i]);
            res%=mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
