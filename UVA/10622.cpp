/*
唯一分解定理
将n分解，然后对其所有素因子的指数求gcd即答案

一开始想先素数打表呢，想到一句“写程序不要过早地优化”
再想想复杂度不高(log(n)*log(log(n)))，所有没必要上去就打表.

不过后来事实证明不优化就是TLE。。。。

注意n可以为负，这让我WA了2次。。。
n为负时，答案一定得是奇数。
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxp=100000+10;
bool vis[maxp];
vector<int> prime;

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=100000;j+=i)
                vis[j]=1;
        }
    }
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int solve(long long n){
    int i,g,flag=0;
    for(i=0;i<prime.size();i++){
        if(n<(long long)prime[i]*prime[i]) break;
        int x=prime[i];
        if(n%x==0){
            int c=0;
            while(n%x==0){
                c++;n/=x;
            }
            if(flag==0)
                g=c;
            else g=gcd(g,c);
            flag=1;
        }
    }
    if(n>1) g=1;
    return g;
}

int main()
{
    int i;
    long long n;
    prime_table();
    while(scanf("%lld",&n),n){
        int ans=solve(n<0?-n:n);
        if(n<0)
            while(ans%2==0) ans/=2;
        printf("%d\n",ans);
    }
    return 0;
}
