/****************
*PID:525a div2
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

const int maxn=200000+10;
char s[maxn*2];
int vis[30];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int res=0;
        scanf("%s",s);
        memset(vis,0,sizeof(vis));
        for(i=0;i<2*n-2;i+=2){
            if((s[i]-'a')==(s[i+1]-'A')) continue;
            if(vis[s[i+1]-'A']==0){
                res++;vis[s[i]-'a']++;
            }
            else {
                vis[s[i+1]-'A']--;vis[s[i]-'a']++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
