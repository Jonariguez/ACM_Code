/****************
*PID:poj2402
*Auth:Jonariguez
*****************
长度为k的数字能形成的回文数的个数为：9*10^((k-1)/2)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[22],cnt[22];
int vis[10];

int main()
{
    LL i,j,n;
    fact[0]=1;
    for(i=1;i<=20;i++)          //fact[]和cnt[]算到20,15会WA
        fact[i]=fact[i-1]*10;
    cnt[1]=9;
    for(i=2;i<=20;i++)
        cnt[i]=9*fact[(i-1)/2];
    while(scanf("%lld",&n),n){
        LL k=n,p;
        for(p=1;p<=20;p++)
            if(k<=cnt[p]) break;
            else k-=cnt[p];
      //  printf("%I64d\n",p);
        memset(vis,0,sizeof(vis));      //并不用vis判重，因为构造的数字是可以有重复的。。。，而不是1~n的一个排列
        LL now=0,res=0,m=(p+1)/2;         //p表示第n个回文数是几位数，m表示中间位置，避免了p的奇偶性谈论
        for(i=1;i<=m;i++){          //从1到m位挨个确定数字，后面的按回文规则补全
            LL cnt=0;
            for(j=0;j<10;j++){
                if(j==0 && i==1) continue;
                if(now+fact[m-i]>=k) break;
                now+=fact[m-i];
            }
         //   printf("j=%I64d\n",j);
          //  vis[j]=1;
            res=res*10+j;
        }
        k=res;
        if(p&1) k/=10;  //如果是奇数为，则中间一位不要，从中间一位的前一位至第一位不答案的后面补成回文
        while(k){
            res=res*10+k%10;
            k/=10;
        }
        printf("%lld\n",res);   //I64d会WA。。。。
    }
    return 0;
}
