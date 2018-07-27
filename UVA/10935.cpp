#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n,i,t;
    while(scanf("%d",&n),n){
        if(n==1){
            printf("Discarded cards:\nRemaining card: 1\n");
            continue;
        }
        queue<int> que;
        for(i=1;i<=n;i++)
            que.push(i);
        printf("Discarded cards: 1");
        que.pop();
        t=que.front();
        que.pop();
        que.push(t);
        while(que.size()!=1){
            t=que.front();
            printf(", %d",t);
            que.pop();
            t=que.front();
            que.pop();
            que.push(t);
        }
        printf("\nRemaining card: %d\n",que.front());
        que.pop();
    }
    return 0;
}
