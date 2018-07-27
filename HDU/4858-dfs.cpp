/****************
*PID:hdu4858
*Auth:Jonariguez
*****************
��ͼת���и�����ÿ�β����������ϴ��ǣ������߱�����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
vector<int> G[maxn],g[maxn];
//val��¼�ڵ������ֵ��res[i]��¼�и����ϣ��ڽڵ�i���£��Һͽڵ�i�����Ľڵ������ֵ֮�͡�
//��res�Ķ����֪��ÿ�ζԽڵ�u���޸Ĳ���ֻ�޸�u�ĸ��׺�uָ�����ȵķ����ߣ���ָ������ı�
//��������������Ϊ�ڴ�������ʱ��������Ӱ����µ�u��
int par[maxn],pre[maxn],cnt[maxn],val[maxn],res[maxn],dfs_clock;    //pre[i]��¼dfs��

void dfs(int u,int pa){
    pre[u]=++dfs_clock;
    par[u]=pa;cnt[u]++; //��Ϊ���رߣ�����cnt[u]��¼�ڵ�uָ���׽ڵ�ıߵĸ���
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;     //����߲�����
        if(!pre[v])         //û�����ʹ�
            dfs(v,u);
        else if(pre[v]<pre[u]){    //������
            g[u].push_back(v);
            g[v].push_back(u);
        }else if(par[v]==u) //�رߣ���ôu->v�Ͷ����ߣ���vָ����(u)�ı߾Ͷ�һ����
            cnt[v]++;
    }
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++){
            G[i].clear();g[i].clear();
            pre[i]=cnt[i]=0;
        }
        memset(val,0,sizeof(val));
        memset(res,0,sizeof(res));
        dfs_clock=0;
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1,0);
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int o,u,v;
            scanf("%d",&o);
            if(o==0){
                scanf("%d%d",&u,&v);
                val[u]+=v;
                if(par[u])
                    res[par[u]]+=cnt[u]*v;  //�޸ĶԸ��׵�Ӱ��
                for(i=0;i<g[u].size();i++){
                    int t=g[u][i];
                    if(pre[t]<pre[u]){   //�޸Ķ����ȵ�Ӱ��
                        res[t]+=v;
                    }
                }
            }else {
                scanf("%d",&u);
                int ans=0;      //����3������ɣ����׵�����ֵval[par[u]]+�������Ӱ��res[u]+���ȶ�u��Ӱ��(����)
                if(par[u]) ans=cnt[u]*val[par[u]]; //ע�ⲻҪ���˳�cnt[u]!!!!
                ans+=res[u];
                for(i=0;i<g[u].size();i++){
                    int t=g[u][i];
                    if(pre[t]<pre[u])
                        ans+=val[t];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

/*
1
4 6
1 2
1 3
2 3
3 4
2 4
3 2
30
0 1 2

*/
