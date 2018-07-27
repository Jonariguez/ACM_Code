/****************
*PID:cf570D
*Auth:Jonariguez
*****************
首先是判断回文：如果有超过1种字符出现的次数是奇数，那么就不能
构成回文。
dfs序，每个节点u都有一个开始时间戳start[u]和结束时间戳End[u],
那么以u为根的子树的所有节点的时间戳范围都在(start[u],End[u])里。
对于询问v,h，怎么判断第h层哪些节点是在以v为根的子树里呢？
虽然不知道在哪里，但是在某一层的全部节点中(假设存在dep[i]中)，
那么包含在某个子树里的节点在dep[i]中肯定是连续的。假如我们把整
棵树的第h层的全部节点按从左到右(其实也是按dfs序的大小)存放在dep[h]
容器中，并且dep[h]按dfs序大小排序，那么我们要求的那些节点就在某
个范围内，这个范围是什么呢？
询问v，h，就是在dep[h]中查找值大小在(start[v],End[v])范围内的即为所求。
我们还需要知道每个节点是什么字母，所以我们可以开26个dep，即dep[26][maxH];
dep[i][h]表示在第h层中字母'a'+i出现的开始时间戳，那么求这些时间戳
在(start[v],End[v])范围内的个数就行了。
好题，理解了1个小时。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
char str[maxn];
int depth[maxn];
vector<int> son[maxn];
vector<int> dep[26][maxn];
int dfs_seq,start[maxn],End[maxn],maxdeep;

void dfs(int u,int D){
    dep[str[u]-'a'][D].push_back(++dfs_seq);
    maxdeep=max(maxdeep,D);
    start[u]=dfs_seq;
    for(int i=0;i<son[u].size();i++)
        dfs(son[u][i],D+1);
    End[u]=++dfs_seq;
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    depth[1]=1;
    for(i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        son[x].push_back(i);
        depth[i]=depth[x]+1;
    }
    scanf("%s",str+1);
    dfs_seq=0;
    maxdeep=0;
    dfs(1,1);
    while(m--){
        int v,h;
        scanf("%d%d",&v,&h);
        if(h>maxdeep || h<=depth[v]){   //大于最大深度，或小于v的深度得到的字符串都是空串，则也是回文
            printf("Yes\n");
            continue;
        }
        int odd=0;
        for(i=0;i<26;i++){
            int cnt=upper_bound(dep[i][h].begin(),dep[i][h].end(),End[v])-
                    lower_bound(dep[i][h].begin(),dep[i][h].end(),start[v]);
            if(cnt%2){
                odd++;
                if(odd>1) break;
            }
        }
        if(odd>1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
