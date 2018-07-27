#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=3000+10;
short a[maxn],b[maxn*maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++) scanf("%hd",&a[i]);
        int tot=0;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                b[tot++]=a[i]+a[j];
        sort(b,b+tot);
        for(i=tot-1;i>tot-m-1;i--)
            printf("%hd%c",b[i],i==tot-m?'\n':' ');
    }
    return 0;
}
