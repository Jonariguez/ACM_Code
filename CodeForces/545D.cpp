#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100000+10;
int a[maxn];

int main()
{
    int i,n,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    sum=0;
    ll now=0;
    for(i=0;i<n;i++){
        if(now<=a[i])
            now+=a[i];
        else
            sum++;
    }
    printf("%d\n",n-sum);
    return 0;
}
