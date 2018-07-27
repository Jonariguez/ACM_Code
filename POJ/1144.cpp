/****************
*PID:poj1144
*Auth:Jonariguez
*****************
¸îµã
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int map[maxn][maxn];
int num[maxn],low[maxn],flag[maxn],dfs_seq,n,res;

void dfs(int cur,int fa){
    int i,j,chi=0;++dfs_seq;
    num[cur]=low[cur]=dfs_seq;
    for(i=1;i<=n;i++){
        if(map[cur][i]==0) continue;
        if(num[i]==0){
            chi++;
            dfs(i,cur);
            low[cur]=min(low[cur],low[i]);
            if((cur==1 && chi>1 || cur!=1 && low[i]>=num[cur]) && flag[cur]==0){
                res++;flag[cur]=1;
            }
        }else if(i!=fa)
            low[cur]=min(low[cur],num[i]);
    }
}

int main()
{
    int i,j,a,b;
    while(scanf("%d",&n),n){
        string s;
        memset(map,0,sizeof(map));
        memset(num,0,sizeof(num));
        memset(low,0,sizeof(low));
        memset(flag,0,sizeof(flag));
        while(cin>>s){
            if(s[0]=='0') break;
            stringstream ss(s);
            ss>>a;
            getline(cin,s);
            stringstream sa(s);
            while(sa>>b){
                map[a][b]=map[b][a]=1;
            }
        }
        dfs_seq=0;
        res=0;
        dfs(1,1);
        printf("%d\n",res);
    }
    return 0;
}
