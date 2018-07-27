/****************
*ID:hdu1003
*Auth:Jonariguez
*****************
最大连续和
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,s,t,k,T,sum,now,n,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int x;
        now=0;
        sum=-99999;
        s=t=k=1;        //用k更新标记每个序列的开头
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            now+=x;
            if(now>sum){
                sum=now;
                s=k;
                t=i;
            }
            if(now<0){
                now=0;
                k=i+1;
            }
        }
        printf("Case %d:\n%d %d %d\n",kcase++,sum,s,t);
        if(T)
            printf("\n");
    }
    return 0;
}
