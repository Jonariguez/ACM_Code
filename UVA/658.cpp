/****************
*PID:uva658
*Auth:Jonariguez
*****************
不用位运算超时
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=20;
const int maxm=100+10;
const int INF=1000000000;
int n,m,dist[1<<maxn];
bool vis[1<<maxn];

struct Node{
    int time,bug;
    bool operator < (const Node &r) const {
        return time>r.time;
    }
};

struct Patch{
    int time;
    string first,second;
    bool operator < (const Patch &r) const {
        return time<r.time;
    }
}s[maxm];

void Init_hash_table(){
    memset(vis,0,sizeof(vis));
}

bool try_insert(int v){
    if(!vis[v]){
        vis[v]=1;
        return true;
    }
    return false;
}

bool judge(Node& u,string& b){
    int i;
    for(i=0;i<n;i++){
        if(b[i]=='-' && (u.bug & (1<<i))) return false;
        if(b[i]=='+' && !(u.bug & (1<<i))) return false;
    }
    return true;
}

Node doPatch(Node& u,Patch& p){
    int i;
    Node t;
    t.time=u.time+p.time;
    t.bug=u.bug;
    for(i=0;i<n;i++){
        if(p.second[i]=='-')
            t.bug &= ~(1<<i);
        if(p.second[i]=='+')
            t.bug |= (1<<i);
    }
    return t;
}

int bfs(){
    int i,j,k;
    Init_hash_table();
    for(i=0;i<(1<<n);i++)
        dist[i]=INF;
    Node t;
    t.bug=(1<<n)-1;
    t.time=0;
    priority_queue<Node> que;
    que.push(t);
    dist[t.bug]=0;
    while(!que.empty()){
        Node u=que.top();que.pop();
        if(!try_insert(u.bug))
            continue;
        if(u.bug==0) return u.time;
        for(i=0;i<m;i++){
            if(judge(u,s[i].first)){
                Node t = doPatch(u,s[i]);
                int& D=dist[t.bug];
                if(D<0 || D>t.time){
                    D=t.time;
                    que.push(t);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int i,j,kcase=1,res;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=0;i<m;i++)
            cin>>s[i].time>>s[i].first>>s[i].second;
        sort(s,s+m);
        res=bfs();

        printf("Product %d\n",kcase++);
        if(res==-1)
            printf("Bugs cannot be fixed.\n\n");
        else
            printf("Fastest sequence takes %d seconds.\n\n",res);
    }
    return 0;
}

