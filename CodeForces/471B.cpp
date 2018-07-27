/****************
*PID:471b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=2000+10;
int a[maxn],c[maxn];

struct pp{
    int v,id;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v)
        return x.id<y.id;
    return x.v<y.v;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(c,0,sizeof(c));
        int cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d",&s[i].v);
            if(c[s[i].v]) cnt++;
            c[s[i].v]=1;
            s[i].id=i;
        }
        if(cnt<2){
            puts("NO");continue;
        }
        puts("YES");
        sort(s+1,s+n+1,cmp);
        for(i=1;i<=n;i++)
            printf("%d%c",s[i].id,i==n?'\n':' ');
        for(i=1;i<n;i++)
            if(s[i].v==s[i+1].v){
                swap(s[i],s[i+1]);break;
            }
        for(i=1;i<=n;i++)
            printf("%d%c",s[i].id,i==n?'\n':' ');
        for(i=n;i>1;i--)
            if(s[i].v==s[i-1].v){
                swap(s[i],s[i-1]);break;
            }
        for(i=1;i<=n;i++)
            printf("%d%c",s[i].id,i==n?'\n':' ');
    }
    return 0;
}
