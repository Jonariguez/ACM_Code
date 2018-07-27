/****************
*PID:591b div2
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
char s[maxn];
int vis[30],p[30];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%s",s);
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
            vis[s[i]-'a']++;
        for(i=0;i<30;i++)
            p[i]=i;
        for(i=0;i<m;i++){
            int a,b;
            char aa[2],bb[2];
            scanf("%s %s",aa,bb);
          //  printf("%s %s",aa,bb);
            a=aa[0]-'a';b=bb[0]-'a';
            int x,y;
            for(x=0;x<26;x++)
                if(a==p[x]) break;
            for(y=0;y<26;y++)
                if(b==p[y]) break;
            int t=p[x];p[x]=p[y];p[y]=t;
        }
        for(i=0;i<n;i++)
            printf("%c",'a'+p[s[i]-'a']);
        printf("\n");
    }
    return 0;
}
