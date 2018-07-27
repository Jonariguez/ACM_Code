#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1120;
vector<int> prime;
bool vis[maxn+44];
int dp[maxn+5][15];

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=maxn;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=maxn;j+=i)
                vis[j]=1;
        }
    }
}

int main()
{
    prime_table();
    int i,j,n,k;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=0;i<prime.size();i++){
        int x=prime[i];
        for(j=14;j>=1;j--)
            for(k=1120;k>=x;k--)
                dp[k][j]+=dp[k-x][j-1];
    }
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==0 && k==0) break;
        printf("%d\n",dp[n][k]);
    }
    return 0;
}



