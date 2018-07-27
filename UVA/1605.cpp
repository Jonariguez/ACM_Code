#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void print(int x){
    if(x<=26)
        printf("%c",x-1+'a');
    else
        printf("%c",x-27+'A');
}

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        printf("2 %d %d\n",n,n);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                print(i);
            printf("\n");
        }
        printf("\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                print(j);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
