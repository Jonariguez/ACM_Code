/****************
*PID:hdu5642
*Auth:Jonariguez
*****************
a[i]:表是前i个字符，最后两个字符不同的方案数
b[i]:表示前i个字符，最后两个字符相同的方案数
c[i]:表示前i个字符，最后三个字符相同的方案数
a[i]=a[i-1]*25+b[i-1]*25+c[i-1]*25;
b[i]=a[i-1];
c[i]=b[i-1];
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+10;
const LL mod=1000000007;
LL a[maxn],b[maxn],c[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    a[1]=0;a[2]=25*26;a[3]=25*26*26;
    b[1]=0;b[2]=26;b[3]=25*26;
    c[1]=c[2]=0;c[3]=26;
    for(i=4;i<=2000;i++){
        a[i]=a[i-1]*25+b[i-1]*25+c[i-1]*25;a[i]%=mod;
        b[i]=a[i-1];b[i]%=mod;
        c[i]=b[i-1];c[i]%=mod;
    }
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("26\n");continue;
        }
        printf("%I64d\n",(a[n]+b[n]+c[n])%mod);
    }
    return 0;
}
