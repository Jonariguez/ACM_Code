/****************
*PID:la3708
*Auth:Jonariguez
*****************
利用等比缩放，将整个圆缩放成一个周长为n+m的圆，
于是原有的第i个雕塑的位置可以利用公式得出：i/n*(n+m)
又因为，圆已经缩放成周长为n+m,所以在添加m个雕塑之后
每一个雕塑都在整数点上，而现在n个并不一定在整数点上，
所以此时把n个雕塑中不在整数点上的往离它最近的整数点上
移动，这种移动就是最优的
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double pos,res=0.0;
        for(i=1;i<n;i++){
            pos=(double)i/n*(n+m);
            res+=fabs(pos-floor(pos+0.5))/(n+m);      //floor()是在四舍五入,别忘了除以(n+m),即再转换成长度为1的圆
        }
        printf("%.4lf\n",res*10000);
    }
    return 0;
}
