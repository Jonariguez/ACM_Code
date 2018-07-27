#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int a[110],vis[110],i,j,k,n;
    scanf("%d",&n);
    set<int> s;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        s.insert(i);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(x==1 && vis[i]==0){
                s.erase(i);vis[i]++;
            }
            if(x==2 && vis[j]==0){
                s.erase(j);vis[j]++;
            }
            if(x==3){
                if(vis[i]==0){
                    s.erase(i);vis[i]++;
                }
                if(vis[j]==0){
                    s.erase(j);vis[j]++;
                }
            }
        }
    printf("%d\n",s.size());
    if(s.size()){
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++)
            printf("%d%c",*it,it==s.end()?'\n':' ');
    }
}
