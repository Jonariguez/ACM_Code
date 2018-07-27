/****************
*PID:483c div2
*Auth:Jonariguez
*****************
1 n-1 2 n-2 3....凑够k个后，再按顺序填入即可
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
vector<int> res;

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(k==1){
            for(i=1;i<=n;i++) printf("%d ",i);
            puts("");continue;
        }
        res.clear();
        int s=2,t=n,cnt=0;
        res.push_back(1);
        k--;
        while(k--){
            if(cnt%2==0){
                res.push_back(t);t--;
            }else {
                res.push_back(s);s++;
            }
            cnt++;
        }
        if(cnt&1)
            while(s<=t)
                res.push_back(t--);
        else while(s<=t)
                res.push_back(s++);
        for(i=0;i<n;i++)
            printf("%d ",res[i]);
        puts("");
    }
    return 0;
}
