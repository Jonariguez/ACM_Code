/****************
*ID:poj1320
*Auth:Jonariguez
*****************
佩尔方程:x^2-d*y^2=1
1+2+...+n=(n+1)+(n+2)+..+m
-> n*(n+1)/2 = (m-n)*(m+n+1)/2
-> (2*m+1)^2 - 8*n^2 = 1
令x=2*m+1,y=n 得x^2-8*y^2=1   x1=3,y1=1
迭代公式：
Xn=Xn-1*x1 + d*Yn-1*y1
Yn=Xn-1*y1 + Yn-1*x1
即：
Xn+1 = 3*Xn + 8*Yn
Yn+1 = Xn + 3*Yn
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,res,x1,y1,x2,y2,d;
    x1=3;y1=1;d=8;
    for(i=0;i<10;i++){
        x2=3*x1+8*y1;
        y2=x1+3*y1;
        printf("%10d%10d\n",y2,(x2-1)/2);
        x1=x2;y1=y2;
    }
    return 0;
}
