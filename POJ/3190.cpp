/****************
*PID:poj3190
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;

struct pp{
    int x,id;
    bool mark;
}s[maxn*2];

int stall[maxn],res[maxn];

int cmp(const pp &a,const pp &b){
    if(a.x==b.x)
        return a.mark==true;       //相同时先进再出
    return a.x<b.x;
}

int main()
{
    int i,j,n;
  //  vector<int> res;
    scanf("%d",&n);
    int a,b;
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        s[i*2].x=a;s[i*2].mark=true;
        s[i*2].id=i;
        s[i*2+1].x=b;s[i*2+1].mark=false;
        s[i*2+1].id=i;
    }
    sort(s,s+2*n,cmp);
    int ans=0,cnt=0;
    memset(stall,0,sizeof(stall));
    priority_queue<int,vector<int>,greater<int> > que;
    for(i=1;i<=n;i++)
        que.push(i);
    for(i=0;i<2*n;i++){
        if(s[i].mark){
            cnt++;
            int num=que.top();que.pop();
            res[s[i].id]=num;     //
            stall[s[i].id]=num;     //该id的牛进入了num号stall
        }else {
            int num=stall[s[i].id]; //找到该id的牛进入的stall号，现在牛出来，num号stall空了则加入优先队列
            que.push(num);
            cnt--;
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    for(i=0;i<n;i++)
        printf("%d\n",res[i]);
    return 0;
}
