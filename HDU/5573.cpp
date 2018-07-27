/****************
*PID:hdu5573
*Auth:Jonariguez
*****************
有数据范围N<=2^k,可知，我们只需要
用二叉树的最左边一列k个即可，然后根据n的奇偶性
判断是否要把最下的叶子节点2^k换成2^k+1.
因为最左列的和是sum=2^k-1,设d=sum-n，x=d/2,
这时只需要用2^0,2^1,2^2,..,2^(k-1)构造出x即可，
然后构造x的这些个数取-就好了。
当然如果d是奇数的话，最后一个数取2^k+1，则sum变成sum=2^k
那么d=sum-n就又能保证是偶数。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[65],bit[65],res[65];
int sign[65];
int main()
{
    LL i,j,n,k,T,kcase=1;
    fact[1]=1;
    for(i=2;i<=61;i++)
        fact[i]=fact[i-1]*2;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&k);
        for(i=1;i<=k;i++){
            res[i]=fact[i];sign[i]=1;
        }
        LL d=fact[k+1]-1-n;
        if(n%2==0){
            res[k]++;d++;
        }
        LL x=d/2,cnt=0;
        while(x){
            bit[cnt++]=x%2;x/=2;
        }
        for(i=1,j=0;j<cnt;j++){
            if(bit[j]) sign[i]=0;
            i++;
        }
        printf("Case #%I64d:\n",kcase++);
        for(i=1;i<=k;i++){
            printf("%I64d ",res[i]);
            if(sign[i])
                printf("+\n");
            else printf("-\n");
        }
    }
    return 0;
}

