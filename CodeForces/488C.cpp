/****************
*PID:488c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    LL i,j,n,res,hy,ay,dy,hm,am,dm,h,a,d;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&hy,&ay,&dy,&hm,&am,&dm,&h,&a,&d);
    res=10000000000000LL;
    for(i=max(dm,ay)+1;i<=200;i++){
        for(j=dy;j<=min(100LL,am);j++){
                LL t=(i-ay)*a+(j-dy)*d;
                LL cnt=(hm+i-dm-1)/(i-dm);
                LL temp=hy-cnt*(am-j);
                if(temp<=0)
                    t+=abs(temp)*h+h;       //最后y的hp应该>0
                res=min(res,t);
        }
    }
    printf("%I64d\n",max(res,0LL));
    return 0;
}

