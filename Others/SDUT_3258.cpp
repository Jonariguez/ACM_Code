/****************
*PID:sdut3258
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
int a[maxn],vis[1000005];
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
        memset(vis,0,sizeof(vis));
        LL res=0;
        int t,now;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int cnt=0;
            now=1;
            for(j=0;j<p.size() && (LL)p[j]*p[j]<=(LL)a[i];j++){
                t=p[j];
                if(a[i]%t==0){
                    cnt=0;
                    while(a[i]%t==0){
                        cnt++;a[i]/=t;
                    }
                    if(cnt&1) now*=t;
                }
            }
            if(a[i]!=1) now*=a[i];
            res+=vis[now];
            vis[now]++;
        }
        printf("%d\n",res);
    }
    return 0;
}
