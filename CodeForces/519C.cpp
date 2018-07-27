/****************
*PID:519c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;

int main()
{
    int i,j,k,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n>m){
            k=n;n=m;m=k;
        }
        if(n*2<=m)
            printf("%d\n",n);
        else printf("%d\n",(n+m)/3);
    }
    return 0;
}
