/*
用一个队列que1维护现在排队的队伍的序列(因为
同一个队伍的人会连续在一块)
然后用一个队列数组que2，再为每一个队伍开一个
队列，维护该队伍中每个队员的顺序
来人时，通过编号找到此人所属队伍t，并判断que1
中是否有t：有，则que2[t]中追加此人编号；没有，
则在que1中追加t,并que2[t]中追加此人编号。
这里判断que1中有无t，并不需要什么映射，只需
判断que2[t]是否为空即可
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int maxt=1000+10;
queue<int> que1,que2[maxt];
short team[1000000];

int main()
{
    int i,j,n,kcase=1;
    char s[20];
    while(scanf("%d",&n),n){
        printf("Scenario #%d\n",kcase++);
        while(!que1.empty()) que1.pop();
        for(i=1;i<=n;i++){
            while(!que2[i].empty())
                que2[i].pop();
            int k,x;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);team[x]=i;
            }
        }
        while(scanf("%s",s)){
            if(s[0]=='S') break;
            if(s[0]=='E'){
                int x;
                scanf("%d",&x);
                if(que2[team[x]].empty())
                    que1.push(team[x]);
                que2[team[x]].push(x);
            }else {
                int t=que1.front();
                printf("%d\n",que2[t].front());
                que2[t].pop();
                if(que2[t].empty())
                    que1.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
