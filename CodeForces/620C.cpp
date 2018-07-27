/****************
*PID:620c edu
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

const int maxn=300000+10;
int a[maxn];
map<int,int> mp;
vector<int> ans;

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        res=0;
        mp.clear();
        ans.clear();
        int last=1;
        for(i=1;i<=n;i++){
            if(mp[a[i]]){
                res++;
                ans.push_back(last);ans.push_back(i);
                last=i+1;
                mp.clear();continue;
            }
            mp[a[i]]++;
        }
        if(res==0)
            puts("-1");
        else {
            ans[ans.size()-1]=n;
            printf("%d\n",res);
            for(i=0;i<ans.size();i+=2)
                printf("%d %d\n",ans[i],ans[i+1]);
        }
    }
    return 0;
}
