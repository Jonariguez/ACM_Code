#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n,a;
    scanf("%d%d",&n,&a);
    int rot=n-a;
    int flag=1;
    for(i=1;i<n;i++){
        scanf("%d",&a);
        if(i&1)
            a=(a+n-rot)%n;
        else a=(a+rot)%n;
        if(a!=i){
            flag=0;
            break;
        }
    }
    if(flag)
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
