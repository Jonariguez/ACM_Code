/****************
*PID:621b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
set<int> ss;
map<int,LL> mp1,mp2;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        mp1.clear();mp2.clear();
        int x,y;
        for(i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            mp1[x+y]++;mp2[x-y]++;
        }
        map<int,LL>::iterator it;
        LL res=0;
        for(it=mp1.begin();it!=mp1.end();it++)
            res+=(*it).second*((*it).second-1)/2;
        for(it=mp2.begin();it!=mp2.end();it++)
            res+=(*it).second*((*it).second-1)/2;
        printf("%I64d\n",res);
    }
    return 0;
}
