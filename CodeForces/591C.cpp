/****************
*PID:591c div2
*Auth:Jonariguez
*****************
只会有01交错时，才会一直进行
那么i=1，j=i+1开始，一直出现00或者11，然后更新中间的，
中间的有cnt个都需要变换，而次数是(cnt+1)/2,所以挨个找出
这些区间处理就是了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
int a[maxn];
vector<int> ans;

int main()
{
    int i,j,k,n,res,cnt;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ans.clear();
        res=0;
        int f=0;
        for(i=1;i<n;){
            cnt=0;
            for(j=i+1;j<=n;j++){
              //  if(a[j-1]==a[j+1] && a[j-1]!=a[j]) cnt++;
                if(a[j]==a[j-1]) break;
            }
            if(j==i+1){
                ans.push_back(a[i]);f=1;
                i++;continue;
            }
            if(j<=n && j==i+2){
                ans.push_back(a[i]);ans.push_back(a[i+1]);f=1;
                i+=2;continue;
            }
            j--;
            cnt=j-i-1;
            res=max(res,(cnt+1)/2);
         //   if((int)ans.size()!=0) ans.pop_back();
            if(a[i]==a[j])
                for(k=i;k<=j;k++) ans.push_back(a[i]);
            else {
                for(k=i;k<=i+cnt/2;k++) ans.push_back(a[i]);
                for(k=i+cnt/2+1;k<=j;k++) ans.push_back(a[j]);
            }
            i=j+1;f=1;
        }
        printf("%d\n",res);
        if((int)ans.size()<n)
            ans.push_back(a[n]);
        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
