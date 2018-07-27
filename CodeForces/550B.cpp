#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[20],l,r,x,n,res;
int b[20];

void dfs(int cur,int cnt,int sum){
    if(sum>r) return ;
    if(n-cur<2-cnt) return ;
    if(cur==n && sum<=r && sum>=l && b[cnt-1]-b[0]>=x)
        res++;
    if(cur>=n) return ;
    dfs(cur+1,cnt,sum);
    b[cnt]=a[cur];
    dfs(cur+1,cnt+1,sum+b[cnt]);
  //  b[cnt]=0;
}

int main()
{
    int i,j;
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    res=0;
    dfs(0,0,0);
    printf("%d\n",res);
    return 0;
}
