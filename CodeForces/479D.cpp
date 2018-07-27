/****************
*PID:479d div2
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
int a[maxn],n,l,s,t;

bool solve(int x){
    s=1;t=1;
    if(x>l) return false;
    if(x==l){
        t=n;return true;
    }
    while(t<=n){
        while(t<=n && a[t]-a[s]<x) t++;
        if(t>n) break;
        if(a[t]-a[s]==x) return true;
        s++;
    }
    return false;
}


int main()
{
    int i,j,x,y;
    while(scanf("%d%d%d%d",&n,&l,&x,&y)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=0;
        bool bx=solve(x),by=solve(y);
      //  printf("bx=%d by=%d\n",bx,by);
        if(bx && by){
            printf("0\n");continue;
        }
        if(bx)
            printf("1\n%d\n",y);
        else if(by)
            printf("1\n%d\n",x);
        else {
            bool b=solve(y+x);
            if(b)
                printf("1\n%d\n",a[s]+x);
            else {
                int yes=0;
                s=1;t=1;
                while(t<=n){
                    while(t<=n && a[t]-a[s]<y-x) t++;
                    if(t>n) break;
                    if(a[t]-a[s]==y-x){
                         if(a[t]-y>0){
                            yes=1;printf("1\n%d\n",a[t]-y);
                         }
                         else if(a[s]+y<l){
                            yes=1;printf("1\n%d\n",a[s]+y);
                         }
                         if(yes) break;
                    }
                    s++;
                }
                if(yes==0)
                    printf("2\n%d %d\n",x,y);
            }
           // else printf("2\n%d %d\n",x,y);
        }
    }
    return 0;
}
