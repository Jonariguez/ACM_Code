/****************
*PID:544a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
char str[maxn],res[30][maxn];
int vis[30];

int main()
{
    int i,j,n,cnt,tot,k;
    while(scanf("%d",&k)!=EOF){
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(vis,0,sizeof(vis));
        tot=0;cnt=0;
        int index=0;
        for(i=1;i<=n;i++){
            if(vis[str[i]-'a']==0){
                res[tot][index]='\0';
                index=0;
                cnt++;res[++tot][index++]=str[i];
                vis[str[i]-'a']=1;
            }else {
                res[tot][index++]=str[i];
            }
            if(cnt==k){
                for(i++;i<=n;i++) res[tot][index++]=str[i];
                res[tot][index]='\0';
                break;
            }
        }
        if(cnt<k)
            printf("NO\n");
        else {
            printf("YES\n");
            for(i=1;i<=tot;i++)
                printf("%s\n",res[i]);
        }
    }
    return 0;
}
