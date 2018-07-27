#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int c[22][22];

void get(){
    int i,j;
    memset(c,0,sizeof(c));
    for(i=0;i<=20;i++)
        for(j=0;j<=20;j++)
            if(j==0 || j==i)
                c[i][j]=1;
            else c[i][j]=c[i-1][j]+c[i-1][j-1];
}

int main()
{
    int i,j,T;
    get();
    for(i=1;i<=10;i++){
        for(j=1;j<=i;j++)
        printf("%d ",c[i][j]);
        printf("\n");
    }
    ll m;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&m);
        if(m==2){
            printf("1\n(2,1)\n");
            continue;
        }
        printf("(%lld,1) (%lld,%lld)",m,m,m-1);
        ll e=(ll)sqrt(m*2);
        if(e*(e+1)==m*2)
            printf(" (%lld,%lld),");
    }
    return 0;
}
