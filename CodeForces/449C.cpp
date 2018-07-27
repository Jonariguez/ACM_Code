/****************
*PID:449c div1
*Auth:Jonariguez
*****************
先处理3到n/2之间的素数x，那么x,2x,3x..tx，t个数两两组队，
如果t是奇数，那么就从这t个中挑一个x的偶数倍(即是个偶数)出来保留，
剩下偶数个两两配对。如果t是偶数则不用处理，直接配对。
处理完之后再处理2，把2的倍数+前面挑出来的没有配对的偶数，这些再
两两配对即可。
注意上面的过程要始终保证不能有重复的。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+5;
int vis[maxn];
vector<int> prime,res,remain;

void table(){
    int i,j;
    vis[1]=1;
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            if((LL)i*i>100000) continue;
            for(j=i*i;j<=100000;j+=i) vis[j]=1;
        }
    }
}

int main()
{
    int i,j,n,m;
    table();
    while(scanf("%d",&n)!=EOF){
        res.clear();remain.clear();
        memset(vis,0,sizeof(vis));
        LL now;
        for(i=1;i<prime.size() && prime[i]<=n/2;i++){
            int cnt=0,f=0;
            for(j=1;j*prime[i]<=n;j++){
                if(vis[j*prime[i]])  continue;
                if(j%2==0 && f==0){
                    remain.push_back(j*prime[i]);f=1;
                    vis[j*prime[i]]=1;
                }else {
                    res.push_back(j*prime[i]);vis[j*prime[i]]=1;
                }
                cnt++;
            }
            if(cnt%2==0){
                if(f){      //如果一共有偶数个prime[i]的倍数，那么就让他们两两配对，即把reamin里的还给res
                    res.push_back(remain[remain.size()-1]);remain.pop_back();
                }
            }else {
                if(f==0)
                    res.pop_back(); //如果一共有奇数个prime[i]的倍数，且都是奇数，那么只能去掉一个不能配对了。
            }
        }
        for(i=2;i<=n;i+=2)
            if(vis[i]==0) res.push_back(i);
        for(i=0;i<remain.size();i++)
            res.push_back(remain[i]);
        printf("%d\n",res.size()/2);
        if(res.size()>=2)
            for(i=0;i<res.size()-1;i+=2)
                printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}
