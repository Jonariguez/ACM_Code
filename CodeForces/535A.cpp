/****************
*PID:cf535b div2
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
char str[22][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"
};

char str2[22][20]={"twenty"," thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF){
        if(n<=20)
            printf("%s\n",str[n]);
        else {
            printf("%s",str2[n/10-2]);
            if(n%10){
                printf("-%s\n",str[n%10]);
            }
        }
    }
    return 0;
}
