/****************
*PID:cf573B
*Auth:Jonariguez
*****************
首先，每次destroy时，两边的都会destroy掉，从这个角度
来看的话，那么第i堆(从1开始)最多在第i次destroy时被完全
毁掉。(其实并不严谨，准确的说是，如果第i-1堆需要cnt次
毁完的话，那么第i堆就只需要cnt+1次就好了，所以我们可以
由前一个推出来当前的，所以扫一遍就行了）
但如果第i堆有x个block的话，每次上面都至少减少一个，那么从
这个角度来看的话，把这堆destroy完的话最多需要x次。
那么该堆具体需要几次，就是需上面两者的较小值。
不过要将上面的过程从左向右算一次，还有从右向左算一次，然后
取两者的较小值，然后用res更新其中的最大值就是答案
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

int a[maxn],b[maxn],c[maxn];

int main()
{
    int i,j,res,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[n+1]=0;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
            b[i]=min(b[i-1]+1,a[i]);
        for(i=n;i>=1;i--)
            c[i]=min(c[i+1]+1,a[i]);
        res=1;
        for(i=1;i<=n;i++)
            res=max(res,min(b[i],c[i]));
        printf("%d\n",res);
    }
    return 0;
}
