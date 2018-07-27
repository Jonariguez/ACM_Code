/****************
*PID:490c div2
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

const int maxn=1000000+10;
char str[maxn];
bool pos[maxn];
LL fact[maxn];

int main()
{
    int i,j,n;
    LL a,b;
    while(scanf("%s",str+1)!=EOF){
        scanf("%I64d%I64d",&a,&b);
        n=strlen(str+1);
        for(i=0;i<=n;i++) pos[i]=0;
        fact[n]=1;
        for(i=n-1;i>=1;i--)
            fact[i]=(fact[i+1]*10)%b;
        LL now=0;
        for(i=1;i<=n;i++){
            now=now*10+(str[i]-'0');
            now%=a;
            if(now==0)
                pos[i]=1;
        }
        now=0;
        for(i=n;i>=2;i--){
            now=((str[i]-'0')*fact[i]+now)%b;
            if(now==0 && str[i]!='0' && pos[i-1])
                break;
        }
        if(i==1)
            printf("NO\n");
        else {
            printf("YES\n");
            for(j=1;j<i;j++) printf("%c",str[j]);
            puts("");
            for(;j<=n;j++) printf("%c",str[j]);
            puts("");
        }
    }
    return 0;
}
