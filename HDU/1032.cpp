/****************
*ID:hdu1032
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int cal(int n){
    int cnt=1;
    while(n!=1){
        if(n&1)
            n=3*n+1;
        else n/=2;
        cnt++;
    }
    return cnt;
}

int main()
{
    int a,b,i,res;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d %d ",a,b);
        if(a>b){
            int t=a;a=b;b=t;
        }
        res=0;
        for(i=a;i<=b;i++)
            res=max(res,cal(i));
        printf("%d\n",res);
    }
    return 0;
}
