/*
n/n+n/(n-1)+n/(n-2)+....+1/2+1/1

带分数输出：
整数部分后有一个空格，'-'的长度和分母一样长
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

void print(char c,int l){
    for(int i=0;i<l;i++)
        printf("%c",c);
}

int main()
{
    ll i,j,n;
    while(scanf("%lld",&n)!=EOF){
        ll a=1,b=n,g;
        for(i=n-1;i>0;i--){
            a=a*i+b;
            b*=i;
            g=gcd(a,b);
            a/=g;b/=g;
        }
        a*=n;
        g=gcd(a,b);
        a/=g;b/=g;
        if(a%b==0)
            printf("%lld\n",a/b);
        else {
            ll Int=a/b;
            a%=b;
            int bitInt=(int)log10((double)Int)+1;
            int bitB=(int)log10((double)b)+1;
            print(' ',bitInt+1);
            printf("%lld\n",a);
            printf("%lld ",Int);
            print('-',bitB);
            printf("\n");
            print(' ',bitInt+1);
            printf("%lld\n",b);
        }

    }
    return 0;
}
