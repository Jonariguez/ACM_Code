/****************
*PID:577c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res;
int vis[1100];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            printf("0\n");continue;
        }
        res.clear();
        memset(vis,0,sizeof(vis));
        for(i=2;i<=n;i++){
            if(!vis[i]){
                int t=i;
                while(t<=n){
                    res.push_back(t);t*=i;
                }
                for(j=i*2;j<=n;j+=i){
                    vis[j]=1;
                }
            }
        }
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
             printf("%d ",res[i]);
        puts("");
    }
    return 0;
}
