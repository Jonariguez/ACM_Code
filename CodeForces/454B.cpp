/****************
*PID:454b div2
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
int a[maxn*2];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int maxv=maxn,index=0,cnt=1;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i+n]=a[i];
        }
        for(i=0;i<n*2-1;i++){
            if(a[i]<=a[i+1])
                cnt++;
            else cnt=1;
            if(cnt==n) break;
        }
        if(cnt<n)
            printf("-1\n");
        else printf("%d\n",(2*n-i-2)%n);
    }
    return 0;
}

