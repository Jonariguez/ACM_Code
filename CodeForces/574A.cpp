/****************
*PID:cf574A
*Auth:Jonariguez
*****************
¶þ·Ö
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=300;
int a[maxn],b[maxn],n;

bool C(int x){
    int now=a[1]+x,i,cnt=0;
    memcpy(b,a,sizeof(a));
    for(i=2;i<=n;i++)
        while(b[i]>=now){
            cnt++;b[i]--;
        }
    return cnt<=x;
}

int main()
{
    int i,res;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=1000000;
    while(l<=r){
        int m=(l+r)/2;
        if(C(m))
            r=m-1;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}
