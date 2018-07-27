/****************
*PID:469a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[110];

int main()
{
    int i,j,n,res=0;
    scanf("%d",&n);
    int p,q,x;
    scanf("%d",&p);
    while(p--){
        scanf("%d",&x);
        if(a[x]==0) res++;
        a[x]++;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        if(a[x]==0) res++;
        a[x]++;
    }
    if(res==n)
        puts("I become the guy.");
    else puts("Oh, my keyboard!");
    return 0;
}
