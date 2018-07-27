/****************
*PID:hdu5587
*Auth:Jonariguez
*****************
sum=1，cnt=1，分别代表初始时数列的总和和元素个数。
每复制一次sum的变化：sum=sum*2+cnt+1;
cnt的变化:cnt=cnt*2+1
一直构造大于等于m个，然后一步一步退回来，
cnt--;cnt/=2;
sum-=cnt+1;sum/=2;
因为每次会用0隔开一次，m--。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    LL i,j,n,m;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&m);
        LL now=1,cnt=1,sum=1,res=0;
        while(true){
           // res+=sum;
            if(cnt*2+1>=m) break;
            sum=(sum*2+cnt+1);
            cnt=(cnt*2+1);
        }
        res+=sum;
        m-=cnt;
        res+=m;
        m--;
        while(m>0){
            if(m>(cnt/2)){
                res+=(m-cnt/2);
                cnt--;cnt/=2;sum-=(cnt+1);
                sum/=2;
                res+=sum;
                m-=cnt;m--;
            }else {
                cnt--;cnt/=2;sum-=(cnt+1);sum/=2;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}

