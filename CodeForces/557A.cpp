/*
�Ȱ�3����min�����ˣ�Ȼ���1~3��ʣ�µĲ���
*/
#include <stdio.h>
#include <string.h>

int maxv[5],minv[5],p[5];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=3;i++)
            scanf("%d%d",&minv[i],&maxv[i]);
        for(i=1;i<=3;i++){
            p[i]=minv[i];
            n-=p[i];
        }
        for(i=1;i<=3;i++){
            if(n>=maxv[i]-p[i]){
                n-=maxv[i]-p[i];
                p[i]=maxv[i];
            }
            else {
                p[i]+=n;
                break;
            }
        }
        for(i=1;i<=3;i++)
            printf("%d%c",p[i],i==3?'\n':' ');
    }
    return 0;
}
