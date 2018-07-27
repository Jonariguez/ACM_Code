#include <stdio.h>
#include <string.h>

bool judge(int n){
    if(n==0 || n==1) return false;
    if(n%2==0) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    int i,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==4)
            printf("2\n");
        else if(judge(n))
            printf("%d\n",n-1);
        else printf("0\n");
    }
    return 0;
}
