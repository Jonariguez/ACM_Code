/****************
*PID:cdvs3027
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int dp[maxn];

struct seg{
    int st,en,c;
}s[maxn];

int cmp(const seg &x,const seg &y){
    return x.en<y.en;
}

bool over(int i,int j){
    return s[i].en<=s[j].st;
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d%d",&s[i].st,&s[i].en,&s[i].c);
    sort(s+1,s+n+1,cmp);
    dp[1]=s[1].c;
    for(i=2;i<=n;i++){
        dp[i]=max(dp[i-1],s[i].c);      //这里不能只写dp[i]=s[i].c，因为有可能第i条线段不用选，所以要取一下max
        for(j=i;j>=1;j--){
            if(over(j,i)){
                dp[i]=max(dp[i],dp[j]+s[i].c);
            }
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
