/****************
*PID:483a div2
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

const int maxn=100000+10;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,m,res;
    LL a,b,c,l,r;
    while(scanf("%I64d%I64d",&l,&r)!=EOF){
        int yes=1;
        for(a=l;a<r && yes;a++){
            for(b=a+1;b<=r&& yes;b++){
                for(c=b+1;c<=r && yes;c++){
                    if(gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)!=1){
                        printf("%I64d %I64d %I64d\n",a,b,c);
                        yes=0;
                    }
                }
            }
        }
        if(yes)
            puts("-1");
    }
    return 0;
}
