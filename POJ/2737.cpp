/****************
*PID:poj2737
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
LL x[maxn],y[maxn],cnt[maxn];
map<double,LL> mp[maxn];

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&x[i],&y[i]);
            cnt[i]=0;
            mp[i].clear();
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j) continue;
                if(x[j]==x[i]){
                    cnt[i]++;continue;
                }
                double k;
                k=(y[j]-y[i])*10000.0/(x[j]-x[i]);
                mp[i][k]++;
            }
        }
        LL res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(j==i) continue;
                if(x[j]==x[i])
                    res=max(res,cnt[i]+1);
                else {
                    double k;
                    k=(y[j]-y[i])*10000.0/(x[j]-x[i]);
                    res=max(res,mp[i][k]+1LL);
                }
            }
        }
        if(res<=3)
            printf("Photo %d: 0 points eliminated\n",kcase++);
        else
            printf("Photo %d: %I64d points eliminated\n",kcase++,res);
    }
    return 0;
}
