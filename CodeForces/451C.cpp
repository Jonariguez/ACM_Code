/****************
*PID:451c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    int i,j,T;
    LL n,k,d1,d2;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
        if(n%3){
            printf("no\n");continue;
        }
        int yes=0;
        LL sum=0,t;
        sum=2*d1+d2;
        t=k-d2*2-d1;
        if(t>=0 && t%3==0 && sum<=n-k && (n-k-sum)%3==0){
            printf("yes\n");continue;
        }
        sum=abs(d1-d2)+max(d1,d2);
        t=k-d1-d2;
        if(t>=0 && t%3==0 && sum<=n-k && (n-k-sum)%3==0){
            printf("yes\n");continue;
        }
        sum=d1+d2*2;
        t=k-2*d1-d2;
        if(t>=0 && t%3==0 && sum<=n-k && (n-k-sum)%3==0){
            printf("yes\n");continue;
        }
        sum=d1+d2;
        if(d1>d2){
            t=d1;d1=d2;d2=t;
        }
        t=k-d2-(d2-d1);
        if(t>=0 && t%3==0 && sum<=n-k && (n-k-sum)%3==0){
            printf("yes\n");continue;
        }
        printf("no\n");
    }
    return 0;
}
