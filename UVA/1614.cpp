/****************
*PID:uva1614
*Auth:Jonariguez
*****************
因为1<=a[i]<=i,可用数学归纳法证明:用a[1]-a[i]的部分或全
部元素通过求和，一定可以凑出1~sum[i]的每个整数（sum[i]是前 i 个元素的和）.
设所有元素的和为sum，(sum为奇无解)只需要从大到小构造出sum/2即可，一路贪心
一定有解。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int a[maxn],sign[maxn],id[maxn];
ll sum;

//按a[i]的大小来排序id数组
int cmp(int x,int y){
    return a[x]<a[y];
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            id[i]=i;
        }
        if(sum&1){
            printf("No\n");
            continue;
        }
        sum/=2;
        sort(id+1,id+n+1,cmp);
        sort(a+1,a+n+1);
        fill(sign,sign+n+1,-1);
        for(i=n;i>=1;i--){
            if(sum<a[i])
                sign[id[i]]=1;
            else
                sum-=a[i];
        }
        printf("Yes\n");
        for(i=1;i<=n;i++)
            printf("%d%c",sign[i],i==n?'\n':' ');
    }
    return 0;
}

