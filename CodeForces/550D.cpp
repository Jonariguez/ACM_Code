#include <stdio.h>
#include <string.h>

int k,n;

void print(int x){
    int i,j;
    for(i=2;i<=k;i++){
        printf("%d %d\n",1+x,i+x);
        printf("%d %d\n",n-1+x,i+x);
        printf("%d %d\n",n+x,i+x);
    }
    printf("%d %d\n",n-1+x,n+x);
    int t=(k-3)/2;
    for(i=2;i<k;i++){
        int cnt=0;
        for(j=i+1;j<=k && cnt<t;j++,cnt++)
            printf("%d %d\n",i+x,j+x);
        j++;
        for(;j<=k;j++)
            printf("%d %d\n",i+x,j+x);
    }
}

int main()
{
    int i,j;
    scanf("%d",&k);
    if(k==1){
        printf("YES\n2 1\n1 2\n");
        return 0;
    }
    if(k%2==0){
        printf("NO\n");
        return 0;
    }
    n=k+2;
    printf("YES\n");
    printf("%d %d\n",n*2,(n*2*k)/2);
    printf("1 %d\n",n+1);
    print(0);
    print(n);
    return 0;
}

