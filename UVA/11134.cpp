/****************
*PID:uva11134
*Auth:Jonariguez
*****************
行和列是独立的，可以单独处理。
对于行，每个矩形在行上的投影就是一条线段，就按线段的
起点排序(升序，起点相等的按终点)，然后贪心选择。
列一样。(错......)
事实证明：左端点由大到小排序，右端点有小到大排序，然后对
每个区间优先选择右边的点即可。
(把上面的话的左、右，大、小交换同样正确)
http://www.myext.cn/other/a_27249.html
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=5000+5;
int n,ansx[maxn],ansy[maxn],R[maxn],C[maxn];

struct pp{
    int l,r,id;
}col[maxn],row[maxn];

int cmp(const pp &a,const pp &b){
    if(a.l==b.l)
        return a.r<b.r;
    return a.l>b.l;
}

bool solve(pp *s,int *ans,int *vis){
    int i,j;
    for(i=0;i<=n;i++) vis[i]=0;
    for(i=1;i<=n;i++){
        for(j=s[i].r;j>=s[i].l;j--)
            if(vis[j]==0){
                ans[s[i].id]=j;vis[j]=1;break;
            }
        if(j<s[i].l) return false;
    }
    return true;
}

int main()
{
    int i,j,res;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d",&col[i].l,&row[i].l,&col[i].r,&row[i].r);
            col[i].id=row[i].id=i;
        }
        sort(col+1,col+n+1,cmp);
        sort(row+1,row+n+1,cmp);
        if(solve(col,ansx,C) && solve(row,ansy,R))
            for(i=1;i<=n;i++)
                printf("%d %d\n",ansx[i],ansy[i]);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
