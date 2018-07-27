/*
如果有1则输入-1
如果没有1，则输入1
*/
#include <stdio.h>
#include <string.h>

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,flag;
    while(scanf("%d",&n)!=EOF){
        flag=0;
        int x;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(x==1) flag=1;
        }
        if(flag)
            printf("-1\n");
        else printf("1\n");
    }
    return 0;
}
