#include <stdio.h.>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char a[1010],b[1010];

int main()
{
    int i,j,res,n;
    scanf("%d",&n);
    scanf("%s%s",a,b);
    res=0;
    for(i=0;i<n;i++)
        res+=min(fabs(a[i]-'0'-(b[i]-'0')),10-(fabs(a[i]-'0'-(b[i]-'0'))));
    printf("%d\n",res);
    return 0;
}
