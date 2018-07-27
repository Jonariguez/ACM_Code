/****************
*PID:479c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+10;

struct pp{
    int a,b;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.a==y.a)
        return x.b<y.b;
    return x.a<y.a;
}

int main()
{
    int i,j,n,m,res;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;++i)
            scanf("%d%d",&s[i].a,&s[i].b);
        sort(s+1,s+n+1,cmp);
        res=0;
        int now=1;
        for(i=1;i<=n;i++){
            if(now<=s[i].b)
                now=s[i].b;
            else if(now<=s[i].a)
                now=s[i].a;
        }
        printf("%d\n",now);
    }
    return 0;
}
