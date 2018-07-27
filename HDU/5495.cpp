/****************
*PID:hdu5495
*Auth:Jonariguez
*****************
置换群
关键就是这是1~n的序列，所以必然a[],b[]存在相同的数字，
也就是一定会由一些循环节组成，而每个循环节经过排列
首尾相接一定会有只相错一位的情况，最终的LCS也就是
总长减去循环节的个数，特判自环不减就行了。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn],b[maxn],c[maxn],vis[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            c[a[i]]=b[i];
        }
        int res=n;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                int x=i;
                if(c[x]!=x) res--;      //c[x]!=x不是自环
                while(!vis[x]){
                    vis[x]=1;
                    x=c[x];
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
