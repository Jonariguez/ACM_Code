/****************
*PID:uva10673
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

void Exgcd(LL a,LL b,LL &d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

int main()
{
    LL i,j,n,k,x,p,q,T;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&x,&k);
        LL f=floor((double)x/k),c=ceil((double)x/k);
      //  printf("f=%I64d c=%I64d\n",f,c);
        Exgcd(f,c,n,p,q);
        LL t=c/n;
        LL d=x/n;
        p=((p*d)%t+t)%t;
        q=(x-p*f)/c;
        printf("%I64d %I64d\n",p,q);
    }
    return 0;
}
