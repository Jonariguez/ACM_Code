#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
vector<int> prime;
bool vis[maxn];
int e[maxn];

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=10000;i++){
        if(vis[i]==0){
            prime.push_back(i);
            for(j=i*i;j<=10000;j+=i) vis[j]=1;
        }
    }
}

//n!素数分解后，素数j的指数
void cal(int n,int d){
    int i,j;
    for(i=0;i<prime.size();i++){
        if(n<prime[i]) return ;
        int t=n;
        for(j=prime[i];t/j;j*=prime[i])
            e[i]+=(t/j)*d;
    }
}

int main()
{
    int i,j,p,q,r,s;
    prime_table();
    while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF){
        memset(e,0,sizeof(e));
        cal(p,1);
        cal(q,-1);
        cal(p-q,-1);
        cal(r,-1);
        cal(s,1);
        cal(r-s,1);
        double res=1;
        for(i=0;i<prime.size();i++)
            res*=pow(prime[i],e[i]);
        printf("%.5f\n",res);
    }
    return 0;
}
