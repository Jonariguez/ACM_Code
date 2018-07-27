/****************
*PID:534a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
//typedef long long LL;

const int maxn=100000+10;
int a[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    if(n==1 || n==2){
        printf("1\n1\n");return 0;
    }
    if(n==3){
        printf("2\n1 3\n");return 0;
    }
    if(n==4){
        printf("4\n3 1 4 2\n");return 0;
    }
    printf("%d\n1",n);
    for(i=3;i<=n;i+=2)
        printf(" %d",i);
    for(i=2;i<=n;i+=2)
        printf(" %d",i);
    printf("\n");
    return 0;
}
