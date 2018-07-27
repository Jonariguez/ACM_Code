/****************
*PID:B
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
int head[maxn],vv[maxn*2],nxt[maxn*2],deg[maxn],Size[maxn],e,D,num;
//vector<int> G[maxn];
map<string,int> mp;
map<int,string> vmp;
vector<pair<int,string> > ans;

void Init(){
    memset(head,0,sizeof(head));
    memset(deg,0,sizeof(deg));
    memset(Size,0,sizeof(Size));
    e=1;num=0;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int c;

void dfs(int u,int pa,int d){
    if(d==D-1){
        c+=Size[u];
        return ;
    }
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        dfs(v,u,d+1);
    }
}

int main()
{
    int i,j,n,k,kcase=1,T_T;
    scanf("%d",&T_T);
    string name,name1;
    while(T_T--){
        scanf("%d%d",&n,&D);
        Init();
        mp.clear();vmp.clear();
        ans.clear();
        int id,id1;
        for(i=1;i<=n;i++){
            cin>>name;
            if(!mp.count(name)){
                mp[name]=++num;vmp[num]=name;
                id=num;
            }else id=mp[name];
            scanf("%d",&k);
            while(k--){
                cin>>name;
                if(!mp.count(name)){
                    mp[name]=++num;vmp[num]=name;
                    id1=num;
                }else id1=mp[name];
              //  G[id].push_back(id1);
                add(id,id1);
                Size[id]++;
                deg[id1]++;
            }
        }
      //  printf("cnt=%d\n",cnt);
        for(i=1;i<=num;i++){
            c=0;
            dfs(i,-1,0);
            if(c)
                ans.push_back(make_pair(-c,vmp[i]));
        }
        sort(ans.begin(),ans.end());
        printf("Tree %d:\n",kcase++);
        if(ans.size()<=3){
            for(i=0;i<ans.size();i++)
                cout<<ans[i].second<<" "<<(-1)*(ans[i].first)<<endl;
            continue;
        }
        for(i=0;i<3;i++)
            cout<<ans[i].second<<" "<<(-1)*(ans[i].first)<<endl;
        int last=ans[2].first;
        for(i=3;i<ans.size();i++){
            if(last==ans[i].first){
                cout<<ans[i].second<<" "<<(-1)*(ans[i].first)<<endl;
            }else break;
        }
        if(T_T)
            puts("");
    }
    return 0;
}





