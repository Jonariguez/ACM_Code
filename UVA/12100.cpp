#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Job
{
    int r,id,b;
    Job(int r,int id,int b):r(r),id(id),b(b){}
    bool operator < (const Job &oth) const {        //不出意外的话，如果r相同的话，先加进去的优先级相等 （#）
        return r<oth.r;         //r大的优先
    }
};

int main()
{
    int i,k,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        queue<Job> que;
        priority_queue<Job> pq;
        int r,id,b;
        for(i=0;i<n;i++){
            scanf("%d",&r);
            if(i==m){
                pq.push(Job(r,i,1));
                que.push(Job(r,i,1));
                continue;
            }
            pq.push(Job(r,i,0));
            que.push(Job(r,i,0));
        }
        int res=0;
        while(1){
            Job job=que.front();
            que.pop();
            Job t=pq.top();
            pq.pop();           //优先队列里最高的一样取出来，这样可以解决几个相等的最高级别的连续排在一起
            if(job.r==t.r){
                res++;
                if(job.b) break;
            }
            else {
                que.push(job);
                pq.push(t);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
