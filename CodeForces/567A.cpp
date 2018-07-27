#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn];

int main()
{
    int i,j,n,l,r;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            if(i==1)
                printf("%d %d\n",a[2]-a[1],a[n]-a[1]);
            else if(i==n)
                printf("%d %d\n",a[n]-a[n-1],a[n]-a[1]);
            else
                printf("%d %d\n",min(a[i]-a[i-1],a[i+1]-a[i]),max(a[i]-a[1],a[n]-a[i]));
        }
    }
    return 0;
}
