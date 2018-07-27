/****************
*PID:501a div2
*Auth:Jonariguez
*****************
a^b=c 则 b=a^c
故从叶子节点(即cnt[i]=1)的开始往上删节点，没删除一个就
修改该节点对其父亲节点的sum值的影响,等最下层删完，上面
的就是新的一层叶子节点
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


