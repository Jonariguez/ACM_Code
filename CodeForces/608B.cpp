/****************
*PID:608b div2
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

const int maxn=200000+10;
char s[maxn],t[maxn];
LL sum[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%s%s",s+1,t+1)!=EOF){
        n=strlen(s+1);m=strlen(t+1);
        memset(sum,0,sizeof(sum));
        sum[0]=0;
        for(i=1;i<=m;i++) sum[i]=sum[i-1]+(t[i]-'0');
        LL res=0;
        for(i=1;i<=n;i++){
            int a=i,b=m-(n-i);
            if(s[i]=='0')
                res+=sum[b]-sum[a-1];
            else res+=(b-a+1)-(sum[b]-sum[a-1]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
