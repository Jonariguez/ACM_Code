/*
二分
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500000+10;
const int INF=1e9+10;
int dp[maxn],dp2[maxn],n,a,b,T;
char str[maxn];

bool C(int x){
    LL now=(LL)INF,sum;
    for(int i=x;i>=1;i--){
        int cnt=x-i;
        int y=n-cnt+1;
        if(i==x)        //不用回来
            sum=dp[i];
        else
            sum=(LL)dp[i]+(i-1)*a+dp2[y]-dp2[1];
        now=min(now,sum);
        if(y<=n){
            if(y>2)
                sum=(LL)dp2[y]+cnt*a+dp[i]-dp[1];
            else sum=dp2[2];
            now=min(now,sum);
        }
    }
    return now<=(LL)T;
}

int main()
{
    int i,j;
    while(scanf("%d%d%d%d",&n,&a,&b,&T)!=EOF){
        scanf("%s",str+1);
        for(i=0;i<=n+1;i++)
            dp[i]=dp2[i]=INF;
        if(str[1]=='h' && T>=1)
            dp[1]=1;
        if(str[1]=='w' && T>=b+1)
            dp[1]=b+1;
        if(dp[1]==INF){
            printf("0\n");continue;
        }
        int now=dp[1];
        for(i=2;i<=n;i++){
            if(str[i]=='h'){
                if(now+a+1>T) break;
                now+=a+1;dp[i]=now;
            }else {
                if(now+a+b+1>T) break;
                now+=a+b+1;dp[i]=now;
            }
        }
        dp2[1]=dp[1];
        now=dp[1];
        for(i=n;i>=2;i--){
            if(str[i]=='h'){
                if(now+a+1>T) break;
                now+=a+1;dp2[i]=now;
            }else {
                if(now+a+b+1>T) break;
                now+=a+b+1;dp2[i]=now;
            }
        }
        dp2[n+1]=dp2[1];
        int L=0,R=n;
        while(L<R){
            int M=L+(R-L+1)/2;
            if(C(M))
                L=M;
            else R=M-1;
        }
        printf("%d\n",L);
    }
    return 0;
}

