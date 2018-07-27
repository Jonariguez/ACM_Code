/****************
*PID:465b div2
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
int a[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        int p=0,t=n;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(p==0 && a[i]) p=i;
        }
        if(p==0){
            printf("0\n");continue;
        }
        while(a[t]==0) t--;
        int cnt=0,res=0;
        for(i=p;i<=t;i++){
            if(a[i]==0)
                cnt++;
            else {
                if(cnt>1)
                    res-=cnt-1;
                cnt=0;
            }
        }
        printf("%d\n",t-p+1+res);
    }
    return 0;
}

