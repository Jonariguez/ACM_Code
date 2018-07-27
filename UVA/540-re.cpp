/****************
*PID:uva540
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
queue<int> que1,que2[maxn];

int main()
{
    int i,j,t,n,kcase=1;
    while(scanf("%d",&t),t){
        map<int,int> team;
        for(i=1;i<=t;i++){
            int cnt,x;
            scanf("%d",&cnt);
            while(cnt--){
                scanf("%d",&x);team[x]=i;
            }
            while(!que2[i].empty())
                que2[i].pop();
        }
        while(!que1.empty())
                que1.pop();
        printf("Scenario #%d\n",kcase++);
        char st[20];
        int x;
        while(scanf("%s",st)){
            if(st[0]=='S') break;
            if(st[0]=='E'){
                scanf("%d",&x);
                if(que2[team[x]].empty()){
                    que2[team[x]].push(x);
                    que1.push(team[x]);
                }else
                    que2[team[x]].push(x);
            }else {
                int d=que1.front();
                printf("%d\n",que2[d].front());
                que2[d].pop();
                if(que2[d].empty())
                    que1.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
