/****************
*PID:489a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int a[maxn];

struct pp{
    int v,id;
    bool operator < (const pp &r) const {
        return v>r.v;
    }
};

priority_queue<pp> pq;

vector<int> res;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        //mp.clear();
        res.clear();
        while(!pq.empty())
            pq.pop();
        pp u;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            u.v=a[i];u.id=i;
            pq.push(u);
        }
        int k=0;
        i=0;
        while(!pq.empty()){
            u=pq.top();pq.pop();
            if(u.id<i) continue;
            int x=u.id;
            if(x!=i){
                res.push_back(i);res.push_back(x);
                int t=a[i];a[i]=a[x];a[x]=t;
                u.v=a[x];
                pq.push(u);
                k++;
            }
            i++;
        }
        printf("%d\n",k);
        for(i=0;i<res.size();i+=2)
            printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}
