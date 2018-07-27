/****************
*PID:uva11401
*Auth:Jonariguez
*****************
设y<=z<x，y+z>x 枚举y得z的个数
计算全部的，减去y==z的情况，和重复的
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000000+5;
ll f[maxn];

int main()
{
    ll i,n;
    f[3]=0;
    for(i=4;i<=1000000;i++)
        f[i]=f[i-1]+((i-2)*(i-1)/2-(i-i/2-1))/2;
    while(scanf("%lld",&n)){
        if(n<3) break;
        printf("%lld\n",f[n]);
    }
    return 0;
}
