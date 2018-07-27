/****************
*PID:630i
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

LL Com(LL n,LL m){
    LL res=n;
    for(LL i=2;i<=m;i++){
        n--;
        res*=n;res/=i;
    }
    return res;
}

LL Pow(LL a,LL b){
    LL res=1,i;
    for(i=1;i<=b;i++) res*=a;
    return res;
}

int main()
{
    LL n,i,res;
    while(scanf("%I64d",&n)!=EOF){
        if(n==3){
            printf("24\n");continue;
        }
        LL cnt=2*n-2;
        res=4*3*Pow(4,cnt-n-1)*2;
        LL c=n-3;
        res+=4*3*3*Pow(4,cnt-n-2)*c;
        printf("%I64d\n",res);
    }
    return 0;
}
