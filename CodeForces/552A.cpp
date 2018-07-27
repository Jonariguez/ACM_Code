#include <stdio.h>

int main()
{
    int i,j,x1,y1,x2,y2,n;
    int res=0;
    while(scanf("%d",&n)!=EOF){
        res=0;
        while(n--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            res+=(x2-x1+1)*(y2-y1+1);
        }
        printf("%d\n",res);
    }
    return 0;
}
