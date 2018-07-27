#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=10000000;
const int MOD=100000007;
bool vis[maxn+5];
int phifac[maxn+5];

void init(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i*i<=maxn;i++)
        if(!vis[i])
            for(j=i*i;j<=maxn;j+=i)
                vis[j]=1;
    phifac[1]=phifac[2]=1;
    for(i=3;i<=maxn;i++)
        phifac[i]=(ll)phifac[i-1]*(vis[i]==0?i-1:i)%MOD;
}

int main()
{
    int i,j,n,m;
    init();
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        int ans=phifac[m];
        for(i=m+1;i<=n;i++)
            ans=(ll)ans*i%MOD;
        printf("%d\n",(ans-1+MOD)%MOD);
    }
    return 0;
}
