/****************
*PID:490a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> t[4];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=3;i++)
            t[i].clear();
        int x;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            t[x].push_back(i);
        }
        printf("%d\n",min(t[1].size(),min(t[2].size(),t[3].size())));
        for(i=0;i<min(t[1].size(),min(t[2].size(),t[3].size()));i++)
            printf("%d %d %d\n",t[1][i],t[2][i],t[3][i]);
    }
    return 0;
}
