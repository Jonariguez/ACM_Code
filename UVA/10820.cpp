#include <stdio.h>
#include <string.h>

const int maxn=50000+10;
int phi[maxn];

void solve(){
    int i,j;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(i=2;i<=50000;i++){
        if(phi[i]==0){
            for(j=i;j<=50000;j+=i){
                if(phi[j]==0) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    for(i=2;i<=50000;i++)
        phi[i]+=phi[i-1];
}

int main()
{
    int i,j,n;
    solve();
    while(scanf("%d",&n),n)
        printf("%d\n",phi[n]*2-1);
    return 0;
}
