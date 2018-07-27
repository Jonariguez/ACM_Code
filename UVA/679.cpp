#include <stdio.h>

int main()
{
    int i,j,k,d,n;
    while(scanf("%d",&n) && n!=-1){
        while(n--){
            scanf("%d%d",&d,&k);
            int num=1;
            while(--d){
                if(k&1)
                    num=num*2;
                else
                    num=num*2+1;
                k=(k+1)/2;
            }
            printf("%d\n",num);
        }
    }
    return 0;
}
