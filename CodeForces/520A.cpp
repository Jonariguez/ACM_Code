/****************
*PID:520a div2
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
int vis[30];
char s[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        memset(vis,0,sizeof(vis));
        int res=0;
        for(i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                if(vis[s[i]-'a']==0){
                    vis[s[i]-'a']=1;res++;
                }
            }else {
                if(vis[s[i]-'A']==0){
                    vis[s[i]-'A']=1;res++;
                }
            }
        }
        if(res==26)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
