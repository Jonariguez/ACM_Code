/****************
*PID:492c div2
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
    LL a,b;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.b<y.b;
}

LL avg,r;

int main()
{
    LL i,j,n,res,sum;
    while(scanf("%I64d%I64d%I64d",&n,&r,&avg)!=EOF){
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&s[i].a,&s[i].b);
            sum+=s[i].a;
        }
        sort(s+1,s+n+1,cmp);
        LL should=avg*n;
        if(sum>=should){
            printf("0\n");
            continue;
        }
        res=0;
        for(i=1;i<=n;i++){
            if(r-s[i].a<=should-sum){
                res+=(r-s[i].a)*s[i].b;
                sum+=r-s[i].a;
            }else{
                res+=(should-sum)*s[i].b;
                break;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
