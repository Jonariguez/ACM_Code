/****************
*PID:595B
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
const LL MOD=1000000007;
LL fact[11],nine[11],n,k,res,a[maxn],b[maxn];

int main()
{
    LL i,j;
    fact[0]=1;nine[0]=0;
    for(i=1;i<=10;i++){
        fact[i]=fact[i-1]*10;
        nine[i]=nine[i-1]*10+9;
       // printf("%I64d %I64d\n",fact[i],nine[i]);
    }
    while(scanf("%I64d%I64d",&n,&k)!=EOF){
        LL d=n/k;
        for(i=1;i<=d;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<=d;i++)
            scanf("%I64d",&b[i]);
        LL t;
        res=1;
        for(i=1;i<=d;i++){
          //  printf("nine=%I64d\n",nine[k]);
            t=(nine[k]/a[i])%MOD;
            if(b[i])
                t++;
            t=(t-(b[i]*fact[k-1]+nine[k-1])/a[i])%MOD;
            if(b[i])
                t=(t+((b[i]-1)*fact[k-1]+nine[k-1])/a[i])%MOD;
            t=(t+MOD)%MOD;
           // printf("t=%I64d\n",t);
            res=(res*t)%MOD;
        }
        res=(res+MOD)%MOD;
        printf("%I64d\n",res);
    }
    return 0;
}
