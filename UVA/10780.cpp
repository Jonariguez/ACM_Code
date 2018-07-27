/****************
*PID:uva10780
*Auth:Jonariguez
*****************
e1代表素因子p在m中的次数
e2代表素因子p在n中的次数
求全部的e2/e1的最小值即可，为0可无解
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+5;
int n,m,tot,res;
bool vis[maxn];
vector<int> prime;

void prime_table(){
    int i,j;
    for(i=2;i<=10000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=10000;j+=i)
                vis[j]=1;
        }
    }
}

int solve(){
    int e1=0,e2=0,i,res=-1;
    for(i=0;i<prime.size() && prime[i]*prime[i]<=m;i++){
        if(m%prime[i]==0){
            int x=prime[i];
            e1=0;
            while(m%x==0){
                e1++;m/=x;
            }
            e2=0;
            for(;x<=n;x*=prime[i])
                e2+=n/x;
            if(res==-1 || res>=e2/e1)
                res=e2/e1;
        }
    }
    if(m>1){
        e2=0;
        int x=m;
        for(;x<=n;x*=m)
            e2+=n/x;
        if(res==-1 || res>=e2)
                res=e2;
    }
    return res;
}

int main()
{
    prime_table();
    int i,j,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        res=solve();
        printf("Case %d:\n",kcase++);
        if(res==0)
            printf("Impossible to divide\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
