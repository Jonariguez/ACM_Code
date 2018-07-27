/****************
*PID:448b div2
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
char s[maxn],t[maxn];
int vis[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%s%s",s+1,t+1)!=EOF){
        n=strlen(s+1);
        m=strlen(t+1);
        memset(vis,0,sizeof(vis));
        int f=0;
        if(n<m || strcmp(s+1,t+1)==0){
            puts("need tree");continue;
        }
        for(i=1;i<=n;i++)
            vis[s[i]-'a']++;
        for(i=1;i<=m;i++)
            vis[t[i]-'a']--;
        for(i=0;i<26;i++)
            if(vis[i]<0) break;
        if(i<26){
            puts("need tree");continue;
        }
        if(n==m){
            puts("array");
        }else {
            int ok=0;
            j=1;
            for(i=1;i<=n && j<=m;i++){
                if(s[i]==t[j]) j++;
            }
            if(j>m)
                puts("automaton");
            else puts("both");
        }
    }
    return 0;
}

