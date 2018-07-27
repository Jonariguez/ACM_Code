/****************
*PID:476d div2
*Auth:Jonariguez
*****************
gcd(si,sj)=k，则gcd(si/k,sj/k)==1，所以先找互素的话，然后
同时乘以k即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

vector<LL> res;
map<LL,int> mp;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}


int main()
{
    LL i,j,n,k=1,m;
    while(scanf("%I64d%I64d",&n,&k)!=EOF){
        printf("%I64d\n",(6*n-1)*k);
        for(i=0;i<n;i++){
            printf("%I64d %I64d %I64d %I64d\n",(6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k);
        }
    }
    return 0;
}
