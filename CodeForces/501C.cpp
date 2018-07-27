/****************
*PID:501a div2
*Auth:Jonariguez
*****************
a^b=c �� b=a^c
�ʴ�Ҷ�ӽڵ�(��cnt[i]=1)�Ŀ�ʼ����ɾ�ڵ㣬ûɾ��һ����
�޸ĸýڵ���丸�׽ڵ��sumֵ��Ӱ��,�����²�ɾ�꣬����
�ľ����µ�һ��Ҷ�ӽڵ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=(1<<16)+10;
int deg[maxn],sum[maxn],cnt[maxn];
vector<int> res[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        queue<int> que;
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&cnt[i],&sum[i]);
            res[i].clear();
            tot+=cnt[i];
            if(cnt[i]==1) que.push(i);
        }
        while(!que.empty()){
            int u=que.front();que.pop();
            if(cnt[u]==0) continue;
            int t=sum[u];
            res[u].push_back(t);
            sum[t]^=u;
            cnt[t]--;
            if(cnt[t]==1) que.push(t);
        }
        printf("%d\n",tot/2);
        for(i=0;i<n;i++){
            for(j=0;j<res[i].size();j++)
                printf("%d %d\n",i,res[i][j]);
        }
    }
    return 0;
}


