/****************
*PID:uva11076
*Auth:Jonariguez
*****************
加入统计数字1出现的次数 假设0到9每个数次出现ni次
则数字1在固定一位上出出现的次数为 n！/(n0!*(n1-1)!*....*n9!)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

int cnt[15],a[15];
ULL fact[15];

int main()
{
    int i,j,n;
    fact[0]=1;
    for(i=1;i<=12;i++)
        fact[i]=fact[i-1]*i;
    while(scanf("%d",&n),n){
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        if(cnt[0]==n){
            printf("0\n");continue;
        }
        ULL sum=0,res=0,temp=1;
        for(i=0;i<10;i++){
            int x=i;
            if(cnt[x]==0) continue;
            ULL temp=fact[cnt[x]-1];
            for(j=0;j<10;j++){
                if(j==i) continue;
                temp*=fact[cnt[j]];
            }
            temp=fact[n-1]/temp*i;      //这里要乘以i
            sum+=temp;
        }
        for(i=0;i<n;i++){
            res+=sum;
            sum*=10;
        }
        printf("%llu\n",res);
    }
    return 0;
}

