/****************
*PID:479b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
struct pp{
    int v,id;
}s[maxn];
vector<int> ans;

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

int main()
{
    int i,j,n,m,k,res;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&s[i].v);
            s[i].id=i;
        }
        int res=0;
        ans.clear();
        while(k--){
            sort(s+1,s+n+1,cmp);
            if(s[n].v-s[1].v<=1) break;
            res++;
            ans.push_back(s[n].id);
            ans.push_back(s[1].id);
            s[n].v--;s[1].v++;
            sort(s+1,s+n+1,cmp);
        }
        printf("%d %d\n",s[n].v-s[1].v,res);
        for(i=0;i<ans.size();i+=2)
            printf("%d %d\n",ans[i],ans[i+1]);
    }
    return 0;
}
