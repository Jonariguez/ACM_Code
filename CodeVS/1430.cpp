/****************
*PID:cdvs1430
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool Judge(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    if(Judge(n))
        printf("\\t");
    else printf("\\n");
    return 0;
}
