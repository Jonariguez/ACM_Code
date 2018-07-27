/****************
*PID:460b div2
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

vector<LL> res;

LL cal(LL n){
    LL res=0;
    while(n){
        res+=n%10;n/=10;
    }
    return res;
}

int main()
{
    LL a,b,c,i,x,sum;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF){
        res.clear();
        for(sum=1;sum<=81;sum++){
            LL now=1;
            for(i=1;i<=a;i++) now*=sum;
            now*=b;now+=c;
            if(now<=0) continue;
            if(now>=1e9) break;
            x=cal(now);
            if(x==sum)
                res.push_back(now);
        }
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
            printf("%I64d ",res[i]);
        puts("");
    }
    return 0;
}
