#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
short vis[maxn],mark[maxn],tot;
int main()
{
    int i,j,res,cnt,n;
    char s[3];
    while(scanf("%d",&n)!=EOF){
        set<int> S;
        int x;
        memset(vis,0,sizeof(vis));
        res=0;
        int t=0;
        while(n--){
            scanf("%s %d",s,&x);
            if(s[0]=='+'){
                vis[x]=1;
                t++;
                res=max(res,t);
            }else {
                if(vis[x]){
                    vis[x]=0;
                    t--;
                }else {
                    res++;
                   // vis[x]=0;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
