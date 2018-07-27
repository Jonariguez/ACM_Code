#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,k1,k2,s[11];
    while(scanf("%d",&n)!=EOF){
        queue<int> que1,que2;
        scanf("%d",&k1);
        int x;
        for(i=1;i<=k1;i++){
            scanf("%d",&x);
            que1.push(x);
        }
        scanf("%d",&k2);
        for(i=1;i<=k2;i++){
            scanf("%d",&x);
            que2.push(x);
        }
        int res=0;
        while(!que1.empty() && !que2.empty()){
            if(res>100000){
                res=-1;break;
            }
            int t1=que1.front();que1.pop();
            int t2=que2.front();que2.pop();
            if(t1<t2){
                que2.push(t1);que2.push(t2);
            }else {
                que1.push(t2);que1.push(t1);
            }
            res++;
        }
        printf("%d",res);
        if(res!=-1){
            if(que1.empty())
                printf(" 2\n");
            else printf(" 1\n");
        }else
            printf("\n");
    }
    return 0;
}

