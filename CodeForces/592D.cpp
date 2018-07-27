/****************
*PID:592d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=123456+10;
vector<int> edge[maxn];
int n,m,size[maxn],deep[maxn];          //sizeֻ����markΪtrue�ģ���attackted��
bool mark[maxn];

void dfs(int u,int pa){
    size[u]=0;
    if(mark[u])
        size[u]=1;
    int i;
    for(i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v!=pa){
            deep[v]=deep[u]+1;
            dfs(v,u);
            size[u]+=size[v];
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(mark,0,sizeof(mark));
        for(i=0;i<=n;i++)
            edge[i].clear();
        int a,b;
        for(i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(i=0;i<m;i++){
            scanf("%d",&a);
            a--;
            mark[a]=1;
        }
        memset(deep,0,sizeof(deep));
        dfs(0,-1);
        int v=-1;
        for(i=0;i<n;i++)
            if(mark[i] && (v==-1 || deep[v]<deep[i]))
                v=i;
        memset(deep,0,sizeof(deep));
        dfs(v,-1);
        int sum=0,dp=0;
        for(i=0;i<n;i++){
            if(mark[i]) dp=max(dp,deep[i]);
            if(size[i]>0) sum++;        //���size[i]>0��˵����������attackted����Ҫ�������ߵ��ýڵ�
        }
        sum=(sum-1)*2;      //-1��Ϊ�˳�ȥ���ڵ�
        //����֪��ǰ����Ǹ�v��ֱ����һ���˵㣬����Ҫ����һ���˵�
        for(i=0;i<n;i++)
            if(mark[i] && i<v && deep[i]==dp){     //���ȵ���attackted�ģ��پ��Ǳ�vС����deep���
                v=i;break;
            }
        printf("%d\n%d\n",v+1,sum-dp);
    }
    return 0;
}
