/****************
*PID:
*Auth:Jonariguez
*****************
首先按照截止时间的先后排序。对于任意两个任务a和b，
如果a的截止时间在b之前，且a的加工时间比b长，那么
接受了a订单必然要接受b订单。反过来呢，如果b的加工
时间超过了截止时间，那么就找之前的订单，删掉加工时
间最长的那个订单。这样接受的订单数没有变化，而总的加工时间
变短了，为以后接受更多订单做准备。
总要拒绝一些订单的，所以用优先队列维护
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=800000+10;

struct pp{
    int need,due;
    pp(int n=0,int d=0):need(n),due(d){}
    bool operator < (const pp &rhs) const {     //重载<号，作用在sort和priority_queue正好相反
        if(due==rhs.due)
            return need<rhs.need;
        return due<rhs.due;
    };
}s[maxn];

int main()
{
    int i,j,T,res,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i].need,&s[i].due);
        }
        sort(s,s+n);
        priority_queue<int> pq;
        int now=0;
        res=0;
        for(i=0;i<n;i++){
            pq.push(s[i].need);
            now+=s[i].need;
            if(now>s[i].due){
                now-=pq.top();
                pq.pop();
            }
        }
        printf("%d\n",(int)pq.size());
        if(T)
            printf("\n");
    }
    return 0;
}
