/****************
*PID:cf583A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=55;
int h[maxn],v[maxn];
vector<int> res;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        res.clear();
        int x,y;
        for(i=0;i<n*n;i++){
            scanf("%d%d",&y,&x);
            if(h[y]==0 && v[x]==0){
                res.push_back(i+1);
                h[y]=1;v[x]=1;
            }
        }
        for(i=0;i<res.size();i++){
            printf("%d%c",res[i],i==res.size()-1?'\n':' ');
        }
    }
    return 0;
}
