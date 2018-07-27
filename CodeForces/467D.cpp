/****************
*PID:467d div2
*Auth:Jonariguez
*****************
按同义词反向连边建图，然后按每个单词的r和len排序，
然后对于第i个单词dfs一下，把其连接的单词都设置为第i个
因为他们都应该用第i个替换才是最优的。
然后遍历一遍essay，累计答案。
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
typedef long long LL;

const int maxn=100000+5;
int head[maxn*2],vv[maxn*2],nxt[maxn*2],vis[maxn*2],e,idcnt;
string str,t,f;
vector<string> dict;
map<string,int> Id;

void Init(){
    memset(head,0,sizeof(head));
    e=1;idcnt=0;Id.clear();
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

struct node{
    int r,len,id;
    node(int r=0,int len=0,int id=0):r(r),len(len),id(id){}
    bool operator < (const node &x) const {
        if(r==x.r)
            return len<x.len;
        return r<x.r;
    }
}s[maxn];

void dfs(int u,int pa,int x){
    vis[u]=x;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(vis[v]==0 && v!=pa){
            dfs(v,u,x);
        }
    }
}


int main()
{
    int i,j,n,m,l,u;
    while(scanf("%d",&n)!=EOF){
        dict.clear();
        Init();
        for(i=0;i<n;i++){
            cin>>str;
            int r=0;
            l=str.length();
            for(j=0;j<l;j++){
                if(str[j]>='A' && str[j]<='Z')
                    str[j]=('a'+(str[j]-'A'));
                if(str[j]=='r') r++;
            }
            if(!Id.count(str)){
                node u(r,l,++idcnt);
                s[idcnt]=u;
                Id[str]=idcnt;
            }
            dict.push_back(str);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            cin>>str>>t;
            int l1=str.length(),cnt1=0;
            for(j=0;j<l1;j++){
                if(str[j]>='A' && str[j]<='Z') str[j]='a'+(str[j]-'A');
                if(str[j]=='r') cnt1++;
            }
            int l2=t.length(),cnt2=0;
            for(j=0;j<l2;j++){
                if(t[j]>='A' && t[j]<='Z') t[j]='a'+(t[j]-'A');
                if(t[j]=='r') cnt2++;
            }
            if(Id[str]==0){
                node v1(cnt1,l1,++idcnt);
                s[idcnt]=v1;
                Id[str]=idcnt;
            }
            if(Id[t]==0){
                node v2(cnt2,l2,++idcnt);
                s[idcnt]=v2;
                Id[t]=idcnt;
            }
            add(Id[t],Id[str]);
        }
        sort(s+1,s+idcnt+1);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=idcnt;i++){
            if(vis[s[i].id]) continue;
            dfs(s[i].id,-1,i);
        }
        int cnt1=0,cnt2;
        LL R=0,sum=0;
        for(i=0;i<dict.size();i++){
            str=dict[i];
            node u=s[vis[Id[str]]];
            R+=u.r;sum+=u.len;
        }
        printf("%I64d %I64d\n",R,sum);
    }
    return 0;
}
