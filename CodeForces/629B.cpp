/****************
*PID:629b div2
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

const int maxn=5000+10;
struct pp{
    int sex,a,b;
}s[maxn];

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        char t[22];
        for(i=1;i<=n;i++){
            scanf("%s",t);
            scanf("%d%d",&s[i].a,&s[i].b);
            if(t[0]=='F') s[i].sex=0;
            else s[i].sex=1;
        }
        int f=0,m=0;
        res=0;
        for(j=1;j<=366;j++){
            f=m=0;
            for(i=1;i<=n;i++){
                if(s[i].a<=j && s[i].b>=j){
                    if(s[i].sex) m++;
                    else f++;
                }
            }
            res=max(res,min(f,m)*2);
        }
        printf("%d\n",res);
    }
    return 0;
}
