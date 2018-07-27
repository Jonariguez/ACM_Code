/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000

const int maxn=1000000+10;
bool vis[maxn];
vector<int> prime;
double dp[maxn];

void table(){
    int i,j;
    for(i=2;i<N;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<N;j+=i) vis[j]=1;
        }
    }
}

double dfs(int n){
    if(n==1) return 0.0;
    if(vis[n]) return dp[n];
    vis[n]=1;
    double sum=0.0;
    int g=0,p=0;
    for(int i=0;i<prime.size() && prime[i]<=n;i++){
        p++;
        if(n%prime[i]==0){
            g++;
            sum+=dfs(n/prime[i]);
        }
    }
    dp[n]=(sum+p)/g;
    return dp[n];
}

int main()
{
    int i,j,T,n,kcase=1;
    table();
 /*   p[1]=0;g[1]=0;
    memset(g,0,sizeof(g));
    p[1]=1;
    for(i=2;i<=N;i++)
        p[i]=p[i-1]+(vis[i]==0);
    for(i=2;i<=20;i++)
        printf("%d ",p[i]);
    printf("\n");
    for(i=0;i<prime.size();i++){
        for(j=prime[i]*2;j<=N;j+=prime[i])
            g[j]++;
    }*/
    memset(vis,0,sizeof(vis));
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        dfs(n);
        printf("Case %d: %.10f\n",kcase++,dp[n]);
    }
    return 0;
}
