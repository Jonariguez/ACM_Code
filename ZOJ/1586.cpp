/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn][maxn],p[maxn],par[maxn],n,m;

struct pp{
    int a,b,w;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
            par[i]=i;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
        m=0;
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++){
                s[m].a=i;s[m].b=j;
                s[m++].w=a[i][j]+p[i]+p[j]; //权值为一条边加两个接口
            }
        sort(s,s+m,cmp);
        int res=0,cnt=0;
        for(i=0;i<m;i++){
            if(merge(s[i].a,s[i].b)){
                res+=s[i].w;
              //  res+=p[s[i].a]+p[s[i].b];
                if(++cnt==n-1) break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
