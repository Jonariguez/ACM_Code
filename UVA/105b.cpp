#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=10000+10;

int h[maxn];

int main()
{
    int i,j,tot=0,L,R,H;
    int maxv=-1;
    while(scanf("%d%d%d",&L,&H,&R)!=EOF){
        for(i=L;i<R;i++)
            h[i]=max(h[i],H);
        maxv=max(maxv,R);
    }
    for(i=1;i<maxv;i++)
        if(h[i]!=h[i-1])
            printf("%d %d ",i,h[i]);
    printf("%d 0\n",maxv);
    return 0;
}
