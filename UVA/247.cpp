/****************
*PID:uva247
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30;
int n,m,cnt,g[maxn][maxn],v[maxn][maxn];
int vis[maxn];
vector<int> res;
map<string,int> ID;
map<int,string> rID;

int Id(string s){
    if(!ID.count(s))
        ID[s]=cnt++;
    rID[ID[s]]=s;
    return ID[s];
}

void floyd(){
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            g[i][j]=g[i][j]||(g[i][k] && g[k][j]);
}

void dfs(int u){
    int i;
    res.push_back(u);
    for(i=0;i<n;i++)
        if(v[u][i]==1 && vis[i]==0){
            vis[i]=1;
            dfs(i);
        }
}

int main()
{
    int i,j,k,kcase=1,flag=0;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        if(flag)
            printf("\n");
        flag++;
        ID.clear();rID.clear();
        cnt=0;
        memset(g,0,sizeof(g));
        string a,b;
        for(i=0;i<m;i++){
            cin>>a>>b;
            g[Id(a)][Id(b)]=1;
        }
        printf("Calling circles for data set %d:\n",kcase++);
        floyd();
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i!=j && g[i][j] && g[j][i])
                    v[i][j]=1;
        for(i=0;i<n;i++){
            if(vis[i]==0){
                res.clear();
                vis[i]=1;
                dfs(i);
                for(j=0;j<res.size();j++){
                    cout<<rID[res[j]];
                    if(j<res.size()-1)
                        printf(", ");
                    else printf("\n");
                }
            }
        }
    }
    return 0;
}
