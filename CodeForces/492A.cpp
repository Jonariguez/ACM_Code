/****************
*PID:492a div2
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
    int i,j,n,res,cnt;
    while(scanf("%d",&n)!=EOF){
        cnt=1;res=0;
        int now=1;
        while(now<=n){
            res++;
            cnt++;
            n-=now;
            now=(cnt+1)*cnt/2;
        }
        printf("%d\n",res);
    }
    return 0;
}
