/****************
*PID:hdu5586
*Auth:Jonariguez
*****************
设f(x)对应的数组为b，原数组是a
需要求b-a的最大连续和
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
LL a[maxn],b[maxn],vis[maxn];

int main()
{
    LL i,j,n,m,T,res;
    while(scanf("%I64d",&n)!=EOF){
        int x,flag=0;
        res=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            b[i]=(1890*a[i]+143)%10007;
        }
        LL s=1,t=1,indexs=0,indext=0,now=0;
        res=0;
        for(i=1;i<=n;i++){
            now+=b[i]-a[i];
            if(now<=0){
                s=t=i+1;now=0;
            }
            if(now>res){
                res=now;t=i;
                indexs=s;indext=t;
            }
        }
      //  printf("%I64d %I64d",indexs,indext);
        res=0;
        for(i=1;i<indexs;i++) res+=a[i];
        for(;i<=indext;i++) res+=b[i];
        for(;i<=n;i++) res+=a[i];
        printf("%I64d\n",res);
    }
    return 0;
}
