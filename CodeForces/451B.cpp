/****************
*PID:451b div2
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
int a[maxn],b[maxn];

int main()
{
    int i,j,n,s,t;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        s=1;t=n;
        while(s<=n && a[s]==b[s]) s++;
        if(s>n){
            printf("yes\n1 1\n");continue;
        }
        while(t>=1 && a[t]==b[t]) t--;
        int indexs=s,indext=t,d=t;
        while(s<=d && a[s]==b[t]){      //因为这里不能用s<=t，因为这样只判断了一半，但是从s比到t才行
            s++;t--;
        }
        if(s>d){
            printf("yes\n");
            printf("%d %d\n",indexs,indext);
        }else printf("no\n");
    }
    return 0;
}
