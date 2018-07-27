#include <stdio.h>
#include <string.h>
typedef long long ll;

ll d[22][22][22];

void init(){
    ll i,j,k;
    memset(d,0,sizeof(d));
    d[1][1][1]=1;
    d[2][1][2]=1;
    d[2][2][1]=1;
    for(i=2;i<=20;i++)
        for(j=1;j<=20;j++)
            for(k=1;k<=20;k++)
                d[i][j][k]=d[i-1][j-1][k]+d[i-1][j][k-1]+d[i-1][j][k]*(i-2);
}

int main()
{
    int T,l,r,n;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&l,&r);
        printf("%lld\n",d[n][l][r]);
    }
    return 0;
}
