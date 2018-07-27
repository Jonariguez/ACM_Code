/****************
*PID:583B
*Auth:Jonariguez
*****************
Ö±½ÓÄ£Äâ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn];

int main()
{
    int i,j,n,res,p;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        res=0;
        int now=0,cnt=0,s=1,t=n;
        while(cnt<n){
            for(i=1;i<=n;i++)
                if(a[i]<=now){
                    now++;cnt++;a[i]=maxn;
                }
            if(cnt<n) res++;
            for(i=n;i>0;i--)
                if(a[i]<=now){
                    now++;cnt++;a[i]=maxn;
                }
            if(cnt<n) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
