/****************
*PID:573Adiv1
*Auth:Jonariguez
*****************
先求出它们的最小公倍数lcm，然后查看它们从本身
变到lcm是否只需要*2或*3，即令t=lcm/a[i],那么
t的素因子应该没有除了2和3之外的素因子
这样其实会超时。
我们可以向下处理，每个数都一直除以2,3，那么最后剩下的
都相等就可以，不一样则不可以
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long Int;

const int maxn=100000+10;
int a[maxn];

int cal(int n){
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    return n;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]=cal(a[i]);
        }
        bool yes=true;
        for(i=1;i<n;i++){
            if(a[i]!=a[0]){
                yes=false;break;
            }
        }
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
