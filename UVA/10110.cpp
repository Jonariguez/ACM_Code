/****************
*PID:uva10110
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
vector<LL> prime;
bool vis[100000];

void table(){
    LL i,j;
    for(i=2;i<100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<100000;j+=i) vis[j]=1;
        }
    }
}

int main()
{
    LL i,j,n;
    table();
    while(scanf("%I64d",&n) && n!=0){
        LL res=1;
        for(i=0;i<prime.size() && prime[i]*prime[i]<=n;i++){
            if(n%prime[i]==0){
                LL cnt=0;
                while(n%prime[i]==0){
                    cnt++;n/=prime[i];
                }
                res*=(cnt+1);
            }
        }
        if(n!=1)
            res*=2;
        if(res&1)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
