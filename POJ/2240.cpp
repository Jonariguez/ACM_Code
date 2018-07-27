/****************
*PID:poj2240
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=33;
const double INF=100000;
double mp[maxn][maxn];
int n,m,idcnt,vis[maxn][maxn],vv[maxn];
map<string,int> Id;

void Init(){
    Id.clear();
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    memset(vv,0,sizeof(vv));
    idcnt=0;
}

int main()
{
    int i,j,k=1;
    while(scanf("%d",&n),n){
        Init();
        string s;
        for(i=1;i<=n;i++){
            cin>>s;
            Id[s]=i;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) mp[i][j]=INF;
        for(i=1;i<=n;i++)
            mp[i][i]=1;
        string a,b;
        double v;
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            cin>>a>>v>>b;
            mp[Id[a]][Id[b]]=v;
        }
        int ok=0;
        for(int k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(mp[i][j]<mp[i][k]*mp[k][j])
                        mp[i][j]=mp[i][k]*mp[k][j];
                }
            }
        }
        for(i=1;i<=n;i++){
            if(mp[i][i]>1){
                ok=1;break;
            }
        }
        printf("Case %d: ",k++);
        if(ok)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
