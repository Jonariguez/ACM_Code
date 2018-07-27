/****************
*PID:POJ1723
*Auth:Jonariguez
*****************
在y上求中位数，即最优
在x上记录位置，贪心向两边分
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int x[maxn],y[maxn];
map<int,int> L,R,cnt;

int main()
{
    int i,j,n,l,r,res=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    sort(x+1,x+n+1);
    for(i=1;i<=n;i++)
        x[i]-=i;
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    int k1=y[(n+1)/2],k2=x[(n+1)/2];
    for(i=1;i<=n;i++){
        res+=abs(y[i]-k1);
        res+=abs(x[i]-k2);
    }
    printf("%d\n",res);
    return 0;
}
/*    for(i=1;i<=n;i++){
        if(cnt[x[i]]>1){
            while(cnt[x[i]]!=1){
                l=r=x[i];
                while(cnt[l]) l--;
                while(cnt[r]) r++;
                if(x[i]-l>r-x[i]){
                    cnt[r]=1;
                    res+=r-x[i];
                }else {
                    cnt[l]=1;res+=x[i]-l;
                }
                cnt[x[i]]--;
            }
        }
    }*/
