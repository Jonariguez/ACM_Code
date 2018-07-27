/****************
*PID:466b div2
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

int main()
{
    LL i,n,a,b;
    while(scanf("%I64d%I64d%I64d",&n,&a,&b)!=EOF){
        if(n*6<=a*b){
            printf("%I64d\n%I64d %I64d\n",a*b,a,b);continue;
        }
        int yes=0;
        if(a>b){
            LL t=a;a=b;b=t;
            yes=1;
        }
        n*=6;
        LL res=(LL)9e18,rx,ry;
        for(i=1;i<=n;i++){
            LL x=i;
            LL y=(n+x-1)/x;
            if(y<x) break;
            if(x<a) x=a;
            if(y<b) y=b;
            if(x*y<res){
                res=x*y;
                rx=x;ry=y;
            }
        }
        if(yes) swap(rx,ry);
        printf("%I64d\n%I64d %I64d\n",res,rx,ry);

    }
    return 0;
}

