/****************
*PID:630l
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

LL quick_pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1)
            res=(res*a)%100000;
        b/=2;
        a=(a*a)%100000;
    }
    return res;
}

char s[10],t[10];

int main()
{
    int i,j;
    LL n;
    while(scanf("%s",s+1)!=EOF){
        t[1]=s[1];
        t[2]=s[3];
        t[3]=s[5];
        t[4]=s[4];
        t[5]=s[2];
        n=0;
        for(i=1;i<=5;i++)
            n=n*10+(t[i]-'0');
        LL res=quick_pow(n,(LL)5);
        if(res==0){
            printf("00000\n");continue;
        }
        int cnt=0;
        n=res;
        while(n){
            cnt++;n/=10;
        }
        cnt=5-cnt;
        for(i=0;i<cnt;i++) printf("0");
        printf("%I64d\n",res);
    }
    return 0;
}
