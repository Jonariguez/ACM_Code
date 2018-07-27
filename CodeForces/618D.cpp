/****************
*PID:618d com
*Auth:Jonariguez
*****************
x>=y的情况是全走y边，下面只谈论x<y的情况：
题目就是求能把树最少分成多少个链，然后链内走x，链间走y。
考虑当前节点u，它能成链则分为两种情况：
①u和其两个子节点横向成链，且只有在u有2个及以上个数的可与u成链的子节点时(贪心原则),
(所谓可与u成链，就是改子节点连上u之后也是条链。)
这样的话u就不能和其父亲再成链了。(因为u已经属于横向链，不能向上分支与其父相连成链)
②u和其一个子节点纵向成链，这是在u是叶子节点或者u只有一个可与u成链的子节点时，
这样的话u就依然可以和u的父亲再相连成链。
对于以上两种情况，那么处理节点u时就有据可依了：
我们假设某个节点f横向成链，那么该链就已经定型固定，不能再和其父亲成链，我们就认为
它对其父亲的成链没有影响，贡献为0；
而如果某个节点f纵向成链，那么该节点依然可以和其父亲成链，那么贡献就为1，为什么是1呢？
我们就从该节点f的父亲节点p的角度看：p的子节点f可以和p成链，相当于p多了一个可与p成链的
子节点，而满足这样要求的子节点的数目(设为sum)就是我们判断对p节点是进行①(横向成链)还是②(纵向成链)
的依据。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
int head[maxn],nxt[maxn*2],vv[maxn*2],deg[maxn],e;

void Init(){
    memset(head,0,sizeof(head));
    memset(deg,0,sizeof(deg));
    e=1;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int res;    //链的个数

int dfs(int u,int pa){
    int sum=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        sum+=dfs(v,u);  //统计该节点的可与其成链的子节点个数。
    }
    if(sum==0 || sum==1)    //如果可成链的子节点的个数少于2个，那么就纵向成链，并贡献为1，return 1
        return 1;
    res+=sum-1;     //如果可成链的子节点个数>=2，那么u就与其中2个横向成链，其他的sum-2个纵向成链。虽然有sum-2个纵向
    return 0; //成链的，但由于u是横向的，那么这些纵向链也已定型，不再参与“上面的”成链，故u的贡献还是0.(共sum-1条链)
}

int main()
{
    int i,j,n,x,y;
    while(scanf("%d%d%d",&n,&x,&y)!=EOF){
        Init();
        int yes=0;
        for(i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
            deg[a]++;deg[b]++;
            if(deg[a]==n-1 || deg[b]==n-1)  //形成了菊花图.
                yes=1;
        }
        if(x>=y){
            if(yes) printf("%I64d\n",(LL)y*(n-2)+x);
            else printf("%I64d\n",(LL)y*(n-1));
        }else {
            res=0;//res是全局变量，用来统计链的个数，但是最后还有+=dfs，这是因为要考虑根节点1，如果dfs返回0，
            res+=dfs(1,-1);//说明节点1已经横向成链，res就是正确个数，如果返回1，说明根节点1是纵向成链1，其实
            printf("%I64d\n",(LL)(res-1)*y+(LL)(n-res)*x);    //此时res并没有把这个链统计进去，故要再加上1条链。
        }
    }
    return 0;
}

