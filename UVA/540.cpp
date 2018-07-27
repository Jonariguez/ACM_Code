#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int maxt=1000+10;

int main()
{
    int t,n,i,kcase=1;
    while(scanf("%d",&t),t){
        printf("Scenario #%d\n",kcase++);
        map<int,int> team;
        for(i=0;i<t;i++){
            scanf("%d",&n);
            while(n--){
                int x;
                scanf("%d",&x);
                team[x]=i;
            }
        }
        queue<int> q,que[maxt];
        char s[10];
        while(scanf("%s",s)){
            if(s[0]=='S') break;
            if(s[0]=='E'){
                int x,num;
                scanf("%d",&x);
                num=team[x];
                if(que[num].empty())
                    q.push(num);
                que[num].push(x);
            }
            else if(s[0]=='D'){
                int x,num;
                num=q.front();
                x=que[num].front();que[num].pop();
                printf("%d\n",x);
                if(que[num].empty())
                    q.pop();
            }
        }
        printf("\n");       //зЂвт
    }
    return 0;
}






