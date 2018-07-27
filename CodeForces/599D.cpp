/****************
*PID:599d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

struct pp{
    LL a,b;
    bool operator < (const pp &r) const {
        if(a==r.a) return b<r.b;
        return a<r.a;
    }
};

set<pp> sot;

int main()
{
    LL i,j,x;
    while(scanf("%I64d",&x)!=EOF){
        LL n,m;
        sot.clear();
        pp u;
        for(n=1;n<=2000000;n++){
            LL a=6*x+n*n*n-n;
            LL b=3*n*n+3*n;
            if(a%b) continue;
            m=a/b;
            if(n>m) break;
            u.a=n;u.b=m;
            sot.insert(u);
            u.a=m;u.b=n;
            sot.insert(u);
        }
        printf("%d\n",sot.size());
        set<pp>::iterator it;
        it=sot.begin();
        while(it!=sot.end()){
            u=*it;
            printf("%I64d %I64d\n",u.a,u.b);
            it++;
        }
    }
    return 0;
}


