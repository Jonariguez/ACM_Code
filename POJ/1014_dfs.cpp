/****************
*PID:poj1014
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int a[8],sum,sum2;
bool yes;

void dfs(int pre,int now){
    if(yes) return ;
    if(now==sum2){
        yes=true;return ;
    }
    for(int i=pre;i>=1;i--){
        if(a[i]){
            if(now+i<=sum2){
                a[i]--;
                dfs(i,now+i);
                if(yes) break;
            }
        }
    }
}

int main()
{
    int i,kcase=1;
    while(scanf("%d",&a[1])){
        sum=a[1];
        for(i=2;i<=6;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*i;
        }
        if(sum==0) break;
        printf("Collection #%d:\n",kcase++);
        if(sum&1){
            printf("Can't be divided.\n\n");
            continue;
        }
        sum2=sum/2;
        yes=false;
        dfs(6,0);
        if(yes)
            printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
