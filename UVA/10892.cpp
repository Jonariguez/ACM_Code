/****************
*PID:uva10892
*Auth:Jonariguez
*****************
n=p1^r1*p1^r2*...*pk^rk
a=p1^a1*p1^a2*...*pk^ak
b=p1^b1*p1^b2*...*pk^bk
lcm(a,b)=n
则ri=max(ai,bi)
故将n分解后，分步讨论ri
对于ri，分类讨论①ai=ri ②bi=ri ③ai=ri && bi=ri
三类共2*ri+1种情况
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[50000];
vector<int> prime,e;
int n;

void prime_table(){
    long long i,j;
    for(i=2;i<50000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<50000;j+=i)
                vis[j]=1;
        }
    }
}

long long solve(int n){
    e.clear();
    long long i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;n/=i;
            }
            e.push_back(cnt);
        }
    }
    if(n>1)
        e.push_back(1);
    long long res=1;
    for(i=0;i<e.size();i++)
        res*=(2*e[i]+1);
    return res/2+1;
}

int main()
{
    int i,j,res;
    prime_table();
    while(scanf("%d",&n),n){
        printf("%d %lld\n",n,solve(n));
    }
    return 0;
}
