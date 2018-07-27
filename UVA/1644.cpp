#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1299709;
vector<int> prime;
bool vis[maxn+44];

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
    int i,j,n;
    prime_table();
    while(scanf("%d",&n),n){
        if(vis[n]==0){
            printf("0\n");
            continue;
        }
        int id=lower_bound(prime.begin(),prime.end(),n)-prime.begin();
        printf("%d\n",prime[id]-prime[id-1]);
    }
    return 0;
}
