/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int person[200];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&person[i]);
        if(n==1){
            printf("%d\n",person[1]);continue;
        }
        sort(person+1,person+n+1);      //对n个人过河的时间排序，person[1]时间最短，person[n]时间最长
        int res=0;
        while(n>=4)                 //只要剩下的人多于等于4个
        {
            int a,b,x,y;
            a=person[1];b=person[2];x=person[n-1];y=person[n];
            if(2*b<=a+x)            //用第一种策略
                res=res+a+2*b+y;
            else                 //用第二种策略
                res=res+2*a+x+y;
            n-=2;       //把最慢的两个人送过去了，那么总人数就减少2个，这样一直循环
        }
        if(n==3) //最后剩3个人，就让person[1]把person[3]送过去，然后person[1]回来，最后person[1]和person[2]一起过去
            res+=person[1]+person[2]+person[3];
        else if(n==2)       //剩两个人的话就一起过去
            res+=person[2];
        printf("%d\n",res);
    }
}
