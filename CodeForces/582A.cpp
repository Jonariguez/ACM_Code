/****************
*PID:582a div1
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

const int maxn=500+5;
int vis[maxn],res[maxn],p[maxn*maxn];
map<int,int> mp;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        int x;
        for(i=0;i<n*n;i++){
            scanf("%d",&x);
            mp[x]++;
        }
        int pos=n;
        map<int,int>::reverse_iterator it;
        for(it=mp.rbegin();it!=mp.rend();it++){
            if(it->second==0) continue;
            x=it->first;
            while(it->second>0){
                res[pos]=x;
                it->second--;
                for(i=pos+1;i<=n;i++){
                    int t=gcd(res[i],res[pos]);
                    mp[t]-=2;
                }
                pos--;
            }
        }
        for(i=1;i<=n;i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}
