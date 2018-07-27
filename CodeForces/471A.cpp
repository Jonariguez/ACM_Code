/****************
*PID:471a div2
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
int a[maxn],c[maxn];

int main()
{
    int i,j,n=6;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    sort(a+1,a+7);
    if(a[1]!=a[4] && a[2]!=a[5] && a[3]!=a[6]){
        puts("Alien");return 0;
    }
    for(i=1;i<=9;i++)
        if(c[i]==1) break;
    if(i<=9) puts("Bear");
    else puts("Elephant");
    return 0;

}
