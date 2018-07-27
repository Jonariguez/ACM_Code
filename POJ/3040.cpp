/****************
*PID:poj3040
*Auth:Jonariguez
*****************
贪心
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

struct pp{
    LL v,b;
}s[25];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

int main()
{
    int i,j,n;
    LL res,c;
    scanf("%d%I64d",&n,&c);
    for(i=1;i<=n;i++)
        scanf("%I64d%I64d",&s[i].v,&s[i].b);
    sort(s+1,s+n+1,cmp);
    res=0;
    for(i=n;i>=1;i--)
        if(s[i].v>=c) res+=s[i].b;
        else break;
    n=i;j=1;
    while(true){
        LL now=0;
        for(i=n;i>=j;i--){      //从大往小凑
            while(s[i].b && now+s[i].v<c){
                now+=s[i].v;s[i].b--;
            }
            if(s[i].b==0 && i==n) n--;
            if(s[i].b && now+s[i].v==c) break;
        }
        if(i>=j){       //凑够了正好为c的
            res++;s[i].b--;continue;
        }
        for(i=j;i<=n;i++){  //不够的话就从小往大补
            while(s[i].b && now<c){
                now+=s[i].v;s[i].b--;
            }
            if(s[i].b==0 && j==i) j++;
            if(now>=c) break;
        }
        if(now<c)break;
        res++;
    }
    printf("%I64d\n",res);
    return 0;
}


