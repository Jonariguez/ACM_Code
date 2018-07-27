/****************
*PID:515b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;
int a[maxn],b[maxn],vis1[maxn],vis2[maxn],vis[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}


int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int k1,k2;
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        scanf("%d",&k1);
        while(k1--){
            int x;
            scanf("%d",&x);
            vis1[x]=1;
        }
        scanf("%d",&k1);
        while(k1--){
            int x;
            scanf("%d",&x);
            vis2[x]=1;
        }
        int cnt=10000;
        while(cnt--){
            for(i=0;i<n;i++){
                if(vis1[i]){
                    memset(vis,0,sizeof(vis));
                    for(j=i;;j+=n){
                        if(vis[j%m]) break;
                        vis2[j%m]=1;
                        vis[j%m]=1;
                    }
                }
            }
            for(i=0;i<m;i++){
                if(vis2[i]){
                    memset(vis,0,sizeof(vis));
                    for(j=i;;j+=m){
                        if(vis[j%n]) break;
                        vis1[j%n]=1;
                        vis[j%n]=1;
                    }
                }
            }
        }
        int yes=1;
        for(i=0;i<n;i++)
            if(vis1[i]==0){
                yes=0;break;
            }
        for(i=0;i<m;i++)
            if(vis2[i]==0){
                yes=0;break;
            }
        if(yes)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
