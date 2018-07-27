/****************
*PID:hdu5595
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a,b,c;

int F(int x){
    return a*x*x+b*x+c;
}

int main()
{
    int i,j,l,r,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        int maxv=F(l),minv=F(l);
        for(i=l+1;i<=r;i++){
            maxv=max(maxv,F(i));
            minv=min(minv,F(i));
        }
        printf("%d %d\n",maxv,minv);
    }
    return 0;
}

