/****************
*ID:uva11246
*Auth:Jonariguez
*****************
一开始是想用类似筛法来求，肯定是对的，但n太大，超时。
容斥原理:n-n/k+n/k^2 - n/k^3 + n/k^4..
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000000+5;
bool vis[maxn];
int n,k,cnt;

int f(int n,int k){
    int d=1,res=0;
    while(n){
        res+=d*n;
        d=d*(-1);
        n/=k;
    }
    return res;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        printf("%d\n",f(n,k));
    }
    return 0;
}
