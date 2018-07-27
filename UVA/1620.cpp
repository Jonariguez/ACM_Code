/****************
*PID:uva1620
*Auth:Jonariguez
*****************
a1 a2 a3...an
一个序列，把第一个数放到最后面去，其逆序对数
的变化是：x+n-1-2*i，其中x是原来的逆序对数，i是a1的大小排名
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int a[maxn];

int main()
{
    int i,j,cnt,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(j=1;j<i;j++)
                if(a[j]>a[i]) cnt++;
        }
        if(n&1 && cnt&1)
            printf("impossible\n");
        else printf("possible\n");
    }
    return 0;
}
