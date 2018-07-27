/****************
*PID:uva12265
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int height[maxn],ans[maxn*2];
char str[maxn][maxn];
struct Rect{
    int c,h;
    Rect(int c=0,int h=0):c(c),h(h){}
}st[maxn];

int main()
{
    int i,j,n,m,T_T;
    scanf("%d",&T_T);
    while(T_T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        memset(ans,0,sizeof(ans));
        memset(height,0,sizeof(height));
        int now,top=-1;
        for(i=1;i<=n;i++){
            top=-1;         //每一行需要重新更新桟。
            for(now=1;now<=m;now++){
                if(str[i][now]=='#'){
                    height[now]=0;top=-1;
                }else {
                    height[now]++;
                    Rect r(now,height[now]);
                    //注意栈里存的(c,h)中的c可能比now大，所以要找小于now的.且高于height[now]的也不行。
                    while(top>=0 && st[top].h>=r.h) r.c=st[top--].c;
                    if(top<0 || r.h-r.c>st[top].h-st[top].c)
                        st[++top]=r;
                    ans[now-st[top].c+1+st[top].h]++;
                }
            }
        }
        for(i=1;i<=n+m;i++)
            if(ans[i]) printf("%d x %d\n",ans[i],i*2);
    }
    return 0;
}

