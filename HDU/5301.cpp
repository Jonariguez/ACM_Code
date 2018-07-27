#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int x,y,m,n;

int main()
{
    int i,j,ans;
    while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF){
        ans=(min(n,m)+1)/2;
        if(n>m){
            int t=n;
            n=m;m=t;
            t=x;x=y;y=t;
        }
        if(n&1 && x==(n+1)/2 && x==y && n==m){
            printf("%d\n",ans-1);
            continue;
        }
        int left=y,right=m-y+1,up=x-1,down=n-x;
        int res;
        if(min(left,right)>ans)
            res=min(max(up,down),min(left,right));
        else res=ans;
        printf("%d\n",max(res,(n+1)/2));
    }
    return 0;
}
