#include <stdio.h>

const int maxn=5000+10;
int a[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int space=0;
        for(i=1;i<=n;i++){
            int t=a[i],cnt=0;
            for(j=1;j<=n;j++)
                if(a[j]>t) cnt++;
            if(space) printf(" ");
            space++;
            printf("%d",cnt+1);
        }
        printf("\n");
    }
    return 0;
}
