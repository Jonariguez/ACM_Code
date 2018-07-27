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

int solve(int &W){
    int w1,d1,w2,d2,b1,b2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(w1==0)
        b1=solve(w1);   //b1,b2只是记录返回值是否是真
    if(w2==0)
        b2=solve(w2);
    W=w1+w2;        //算出目前这层的总重
    return b1&&b2&&(w1*d1==w2*d2);
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int w;
        if(solve(w)) printf("YES\n");
        else printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
