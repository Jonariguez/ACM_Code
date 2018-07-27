/****************
*PID:507a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
struct pp{
    int a,id;
}s[maxn];

vector<int> res;

int cmp(const pp &x,const pp &y){
    return x.a<y.a;
}

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&s[i].a);
            s[i].id=i;
        }
        sort(s+1,s+1+n,cmp);
        res.clear();
        for(i=1;i<=n;i++){
            if(k>=s[i].a){
                res.push_back(s[i].id);
                k-=s[i].a;
            }else break;
        }
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}
