#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;

struct pp{
    int v,id;
    bool operator < (const pp &rhs) const {
        if(v==rhs.v) return id<rhs.id;
        return v<rhs.v;
    }
};

set<pp> s;

int main()
{
    int i,j,k,x,n;
    ll res;
    while(scanf("%d",&n),n){
        int cnt=1;
        set<pp>::iterator it;
        res=0;
        s.clear();
        while(n--){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                pp t;
                t.v=x;t.id=cnt++;
                s.insert(t);
            }
            it=s.begin();
            res-=(*it).v;
            s.erase(it);
            it=s.end();
            it--;
            res+=(*it).v;
            s.erase(it);
        }
        printf("%lld\n",res);
    }
    return 0;
}
