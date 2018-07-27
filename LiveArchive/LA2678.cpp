/****************
*PID:LA2678
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
int a[maxn];

int main()
{
    int i,j,n,S,s,t,sum;
    while(scanf("%d%d",&n,&S)!=EOF){
        int res=n+1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        s=t=0;
        while(t<=n){
            while(t<n && sum<S){
                sum+=a[t];t++;
            }
            if(sum<S) break;
            res=min(res,t-s);
            sum-=a[s++];
        }
        if(res==n+1)
            printf("0\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
