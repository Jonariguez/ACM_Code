/****************
*PID:488b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[6];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            printf("YES\n1\n1\n3\n3\n");continue;
        }
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n==1){
            printf("YES\n%d\n%d\n%d\n",a[1]+1,a[1]*3-1,a[1]*3);continue;
        }
        if(n==2){
            if(a[1]*3==a[2])
                printf("YES\n%d\n%d\n",a[1]+1,a[2]-1);
            else if(a[1]*3<a[2])
                printf("NO\n");
            else if(a[1]*3>a[2])
                printf("YES\n%d\n%d\n",a[1]+(a[1]*3-a[2]),a[1]*3);
            continue;
        }
        if(n==4){
            int sum=a[1]+a[2]+a[3]+a[4];
            if(sum==2*(a[2]+a[3]) && 2*(a[2]+a[3])==4*(a[4]-a[1]) && sum%4==0 && (a[3]+a[2])%2==0)
                puts("YES");
            else printf("NO\n");
            continue;
        }
        if(n==3){
            if(a[1]*3==a[3])
                printf("YES\n%d\n",a[3]-a[2]+a[1]);
            else if(a[1]*3>a[3] && a[2]+a[3]==a[1]*4)
                printf("YES\n%d\n",a[1]*3);
            else if(a[3]%3==0 && a[3]+a[3]/3==a[2]+a[1])
                printf("YES\n%d\n",a[3]/3);
            else
                printf("NO\n");
        }
    }
    return 0;
}
