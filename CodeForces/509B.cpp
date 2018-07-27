/****************
*PID:509b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int c[maxn],vis[maxn],n;
vector<int> res[maxn];;

bool check(){
    for(int i=1;i<=n;i++)
        if(c[i]>0) return false;
    return true;
}

int main()
{
    int i,j,m,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int a=0,b=101;
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            a=max(a,c[i]);
            b=min(b,c[i]);
            res[i].clear();
        }
        if(a-b>k){
            printf("NO\n");continue;
        }
        memset(vis,0,sizeof(vis));
        int yes=0;
        i=1;
        while(!yes){
            for(j=1;j<=n;j++){
                if(c[j]==1){
                    yes=1;c[j]--;res[j].push_back(1);
                }else if(c[j]>1){
                    c[j]--;res[j].push_back(1);
                }
            }
        }
        for(j=1;j<=n;j++){
            if(c[j]==1){
                yes=1;c[j]--;res[j].push_back(1);
            }else if(c[j]>1){
                c[j]--;res[j].push_back(1);
            }
        }
        if(!check()){
            for(i=2;i<=k;i++){
                for(j=1;j<=n;j++){
                    if(c[j]>0){
                        c[j]--;res[j].push_back(i);
                    }
                }
                if(check()) break;
            }
        }
        if(i>k){
            printf("NO\n");continue;
        }
        printf("YES\n");
        for(i=1;i<=n;i++){
            for(j=0;j<res[i].size();j++)
                printf("%d ",res[i][j]);
            printf("\n");
        }
    }
    return 0;
}

