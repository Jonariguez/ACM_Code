/*
素数打表+尺取
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000;
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
    int i,j,s,t,n,res;
    prime_table();
    while(scanf("%d",&n),n){
        s=t=0;res=0;
        int sum=0;
        while(t<prime.size()){
            while(t<prime.size() && sum<n){
                sum+=prime[t];t++;
            }
            if(sum<n) break;
            if(sum==n) res++;
            sum-=prime[s];
            s++;
        }
        printf("%d\n",res);
    }
    return 0;
}
