/****************
*PID:604b div2
*Auth:Jonariguez
*****************
¶þ·Ö´ð°¸
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int a[maxn],n,k;

bool C(int x){
    int i,cnt=0;
  //  for(i=n;i>0;i--)
  //      if(a[i]>=x) cnt++;
  //      else break;
    int j=n;
    for(i=1;i<j;i++){
        while(i<j && a[i]+a[j]>x){
            j--;cnt++;
        }
        cnt++;j--;
    }
    if(i==j)
        cnt++;
    return cnt<=k;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF){
        int l=0,r=2000000+2;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            l=max(l,a[i]);
        }
        while(l<r){
            int m=(l+r)/2;
            if(C(m))
                r=m;
            else l=m+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
