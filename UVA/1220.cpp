/****************
*PID:uva1220
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200+10;
map<string,int> id;
vector<int> son[maxn];
int n,cnt,dp[maxn][2],f[maxn][2];

int ID(string s){
    if(!id.count(s))
        return id[s]=cnt++;
    return id[s];
}

void dfs(int u,int flag){
    if(son[u].size()==0){
        dp[u][flag]=flag;f[u][flag]=1;
        return ;
    }
    int i,mark=1;
    if(flag==1){
        dp[u][1]=1;
        for(i=0;i<son[u].size();i++){
            int v=son[u][i];
            dfs(v,0);
            dp[u][1]+=dp[v][0];
            if(f[v][0]==0) mark=0;
        }
        f[u][1]=mark;
    }else {
        dp[u][0]=0;mark=1;
        for(i=0;i<son[u].size();i++){
            int v=son[u][i];
            dfs(v,0);dfs(v,1);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            if(dp[v][0]==dp[v][1] || dp[v][0]>dp[v][1] && f[v][0]==0 || dp[v][0]<dp[v][1] && f[v][1]==0)
                mark=0;
        }
        f[u][0]=mark;
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n),n){
        string a,b;
        id.clear();
        cnt=0;
        for(i=0;i<=n;i++)
            son[i].clear();
        cin>>a;
        ID(a);
        for(i=1;i<n;i++){
            cin>>a>>b;
            int d1=ID(a),d2=ID(b);
            son[d2].push_back(d1);
        }
        dfs(0,0);
        dfs(0,1);
        printf("%d ",max(dp[0][0],dp[0][1]));
        if(dp[0][0]>dp[0][1]){
            if(f[0][0])
                printf("Yes\n");
            else printf("No\n");
        }else if(dp[0][0]<dp[0][1]){
            if(f[0][1])
                printf("Yes\n");
            else printf("No\n");
        }else printf("No\n");
    }
    return 0;
}

