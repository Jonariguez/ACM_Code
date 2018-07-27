/****************
*PID:sdut3257
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

const int maxn=100000+10;
LL a[maxn];
bool vis[1000005];
map<LL,LL> mp;
vector<LL> p;
void table(){
    int i,j;
    for(i=2;i<=1000000;i++){
        if(vis[i]==0){
            p.push_back(i);
            if((LL)i*i>1000000) continue;
            for(j=i*i;j<=1000000;j+=i)
                vis[j]=1;
        }
    }
}

int main()
{
    int i,j,n,T;
    table();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        LL res=0,now,need,t;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int cnt=0;
            now=1;need=1;
            for(j=0;j<p.size() && p[j]*p[j]<=a[i];j++){
                t=p[j];
                if(a[i]%t==0){
                    cnt=0;
                    while(a[i]%t==0){
                        cnt++;a[i]/=t;
                    }
                    cnt%=3;
                    if(cnt==1){
                        now*=t;need*=(t*t);
                    }else if(cnt==2){
                        now*=(t*t);need*=t;
                    }
                }
            }
            if(a[i]!=1){
                now*=a[i];need*=((LL)a[i]*a[i]);
            }
            res+=mp[need];
            mp[now]++;
        }
        printf("%lld\n",res);
    }
    return 0;
}
