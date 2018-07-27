/****************
*PID:uva1611
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int a[maxn],vis[maxn],n;
vector<int> res;

void solve(){
    int i,j;
    i=1;
    res.clear();
    while(i<n){
        int p=vis[i];
        if(p==i){
            i++;continue;
        }
        if(n-p>=p-i-1){
            int cnt=p-i;
            res.push_back(i);res.push_back(p+cnt-1);
            int k,t;
            for(k=i;k<p;k++){
                vis[a[k]]=k+cnt;vis[a[k+cnt]]=k;
                t=a[k];a[k]=a[k+cnt];a[k+cnt]=t;
            }
            i++;
        }else {
            int cnt=n-p+1,q=p-cnt;
            res.push_back(q);res.push_back(n);
            int k,t;
            for(k=q;k<p;k++){
                vis[a[k]]=k+cnt;vis[a[k+cnt]]=k;
                t=a[k];a[k]=a[k+cnt];a[k+cnt]=t;
            }
        }
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]=i;
        }
        solve();
        printf("%d\n",(int)res.size()/2);
        for(i=0;i<res.size();i+=2)
            printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}
