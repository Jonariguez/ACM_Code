/****************
*PID:hdu2034
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=110;
map<int,int> mp;

int main()
{
    int i,j,res,n,m;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        set<LL> a,b;
        for(i=0;i<n;i++){
            LL x;
            scanf("%lld",&x);
            a.insert(x);
        }
        for(i=0;i<m;i++){
            LL x;
            scanf("%lld",&x);
            if(a.count(x))
                a.erase(x);
        }
        set<LL>::iterator it;
        if(a.size()==0)
            printf("NULL");
        else for(it=a.begin();it!=a.end();it++)
            printf("%d ",*it);
        puts("");
    }
    return 0;
}
