#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=1003;
int vis[maxn][maxn];

bool is_ok(){
    int i,j;
    for(i=0;i<maxn;i++)
        for(j=0;j<maxn;j++)
            if(vis[i][j]) return false;
    return true;
}

int main()
{
    int i,n,a,b;
    while(scanf("%d",&n),n){
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            vis[a][b]++;
            vis[b][a]--;
        }
        if(is_ok())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
