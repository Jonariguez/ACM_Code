/*
直接SHOOT是条件概率，因为是之前有一个空枪，
如果是SHOOT的话，必须保证这一枪也是空枪，即
两个0连着00(条件概率：在第一枪是空的情况下，
第二枪也空)
而ROTATE则是简单概率，即0出现的概率

移项用乘法比用除法保险
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
const int maxn=220;
char str[maxn];

int main()
{
    int i,a,b,n;
    while(scanf("%s",str)!=EOF){
        n=strlen(str);
        a=b=0;
        for(i=0;i<n-1;i++){
            if(str[i]=='0' && str[i+1]=='0') a++;
            if(str[i]=='0') b++;
        }
        if(str[0]=='0' && str[n-1]=='0') a++;
        if(str[n-1]=='0') b++;
        if(b*b==a*n)
            printf("EQUAL\n");
        else if(a*n>b*b)
            printf("SHOOT\n");
        else printf("ROTATE\n");
    }
    return 0;
}
