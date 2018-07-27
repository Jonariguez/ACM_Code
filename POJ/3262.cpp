/****************
*PID:poj3262
*Auth:Jonariguez
*****************
考虑先送什么样的牛，
T越小越好，D越大越好，取值D/T，则值大者优先
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;

struct cow{
    LL T,D;
    double avg;
}s[maxn];

int cmp(const cow &x,const cow &y){
    return x.avg>y.avg;
}

int main()
{
    int i,j,n;
    LL res,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%I64d%I64d",&s[i].T,&s[i].D);
        s[i].avg=(double)s[i].D/s[i].T;
        sum+=s[i].D;
    }
    sort(s+1,s+n+1,cmp);
    res=0;
    for(i=1;i<=n;i++){
        sum-=s[i].D;
        res+=sum*2*s[i].T;
    }
    printf("%I64d\n",res);
    return 0;
}
