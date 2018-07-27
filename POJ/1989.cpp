/****************
*PID:poj1989
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
const int maxk=10000+10;
int a[maxn],vis[maxk];

int main()
{
    int i,j,n,k,res;
    scanf("%d%d",&n,&k);
    memset(vis,0,sizeof(vis));
    int cnt=0;
    res=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(vis[a[i]]==0){
            cnt++;vis[a[i]]=1;
        }
        if(cnt==k){
            memset(vis,0,sizeof(vis));
            res++;
            cnt=0;
        }
    }
    printf("%d\n",res+1);
    return 0;
}
