#include <stdio.h>

int xx[10005],yy[10005];

int main()
{
    int i,x,y,k,cnt;
    while(scanf("%d",&k)!=EOF){
        cnt=0;
        for(y=k+1;y<=k*2;y++)
            if((k*y)%(y-k)==0){
                xx[cnt]=k*y/(y-k);yy[cnt++]=y;
            }
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
            printf("1/%d = 1/%d + 1/%d\n",k,xx[i],yy[i]);
    }
    return 0;
}
