/****************
*PID:535c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=100000+10;
LL a,b,l;

LL get(LL i){
    return a+b*(i-1);
}

LL getsum(LL x){
    return (get(x)+get(l))*(x-l+1)/2;
}


int main()
{
    int i,j,n;
    LL s,t,m;
    while(scanf("%I64d%I64d%d",&a,&b,&n)!=EOF){
        while(n--){
            scanf("%I64d%I64d%I64d",&l,&t,&m);
            s=get(l);
            if(s>t){
                printf("-1\n");continue;
            }
            LL L=l,R=(t-a)/b+1;
            while(L<=R){
                LL M=(L+R)/2;
                if(getsum(M)<=t*m)
                    L=M+1;
                else R=M-1;
            }
            printf("%I64d\n",L-1);
        }
    }
    return 0;
}
