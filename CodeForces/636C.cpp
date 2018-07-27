/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
map<int,int> mpx,mpy;
map<pair<int,int>,int> mm;

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        mpx.clear();
        mpy.clear();
        mm.clear();
        LL res=0;
        for(i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            res+=mpx[x];res+=mpy[y];
            res-=mm[make_pair(x,y)];
            mpx[x]++;mpy[y]++;
            mm[make_pair(x,y)]++;
          //  printf("%I64d\n",res);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
