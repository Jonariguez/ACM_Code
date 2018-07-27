/****************
*PID:poj3517
*Auth:Jonariguez
*****************
约瑟夫递推式：f[n]=(f[n-1]+m)%n
最后之所以+1，是转换成编号从1开始（上式是从0开始的)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,n,m,k,f;
    while(scanf("%d%d%d",&n,&k,&m)){
        if(n==0 && k==0 && m==0) break;
        f=0;
        for(i=2;i<n;i++)
            f=(f+k)%i;
        f=(f+m)%n;
        printf("%d\n",f+1);
    }
    return 0;
}
