/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
long long sum;

int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF){
        long long x;
        sum=0;
        int cnt=0;
        for(i=0;i<n;i++){
            scanf("%lld",&x);sum+=x;
            if(x!=1){
                cnt++;
            }
        }
        if(cnt==0){
            if(n%2==1)
                puts("Win");
            else
                puts("Lose");
        }else if(cnt==1)
            printf("Win\n");
        else if(sum%2==0)
            puts("Lose");
        else puts("Win");
    }
    return 0;
}
