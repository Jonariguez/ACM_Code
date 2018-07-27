/*
a头牛，b辆车，打开c个门
一共a+b个门
分两种情况：
①选中的门是牛：a/(a+b)
改成车： b/(a+b-c-1)
②选中的门是车：b/(a+b)
改成车： (b-1)/(a+b-c-1)
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

int main()
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
        printf("%.5f\n",(a/(a+b)*b/(a+b-c-1)+b/(a+b)*(b-1)/(a+b-c-1)));
    return 0;
}
