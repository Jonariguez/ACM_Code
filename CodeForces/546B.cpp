#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=3000+10;
int a[maxn],vis[maxn*2];

int main()
{
    int i,j,k,n,x;
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    int res=0;
    sort(a,a+n);
    for(i=0;i<n;i++){
        int t=a[i];
        while(vis[t]>1){
            int j=t+1;
            while(vis[j]) j++;
            res+=j-t;
            vis[j]++;
            vis[t]--;
        }
    }
    printf("%d\n",res);
    return 0;
}
