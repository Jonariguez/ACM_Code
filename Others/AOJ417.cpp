/****************
*ID:AOJ417
*Auth:Jonariguez
*****************
八数码问题
3种hash法
①康托展开   中
②hash函数   快
③STL集合    慢
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef int State[9];

const int maxn=1000000+10;
State sta[maxn],goal;
int dis[maxn];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

//hash函数
const int hashsize=1000003;
int head[hashsize],next[maxn];

void init_table(){
    memset(head,0,sizeof(head));
}

int hash(State& s){
    int v=0;
    for(int i=0;i<9;i++)
        v=v*10+s[i];
    return v%hashsize;
}

int insert_table(int s){
    int h=hash(sta[s]);
    int u=head[h];
    while(u){
        if(memcmp(sta[u],sta[s],sizeof(sta[s]))==0) return 0;
        u=next[u];
    }
    next[s]=head[h];
    head[h]=s;
    return 1;
}


/* 康托展开
int vis[362888],fact[9];
void init_table(){
    fact[0]=1;
    for(int i=1;i<9;i++)
        fact[i]=fact[i-1]*i;
}

int insert_table(int s){
    int x=0,i,j;
    for(i=0;i<9;i++){
        int cnt=0;
        for(j=i+1;j<9;j++)
            if(sta[s][j]<sta[s][i])
                cnt++;
        x+=fact[8-i]*cnt;
    }
    if(vis[x]==1) return 0;
    return vis[x]=1;
}
*/

/* STL
set<int> vis;
void init_table(){
    vis.clear();
}

int insert_table(int s){
    int v=0;
    for(int i=0;i<9;i++)
        v=v*10+sta[s][i];
    if(vis.count(v))
        return 0;
    vis.insert(v);
    return 1;
}
*/
int bfs(){
    int front=1,rear=2;
    init_table();
    memset(dis,0,sizeof(dis));
    while(front<rear){
        State& s=sta[front];
        if(memcmp(goal,s,sizeof(s))==0) return front;
        int i,p;
        for(p=0;p<9;p++)
            if(s[p]==0) break;
        int x=p/3,y=p%3;
        for(i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<0 || xx>=3 || yy<0 || yy>=3) continue;
            int newp=xx*3+yy;               //由xx行yy列，转换成newp编号[0,9)
            State& u = sta[rear];
            memcpy(&u,&s,sizeof(s));        //不要忘了把s复制到u
            u[newp]=s[p];               //交换
            u[p]=s[newp];
            dis[rear]=dis[front]+1;         //用dis记录距离
            if(insert_table(rear))
                rear++;
        }
        front++;
    }
    return 0;
}

int main()
{
    int i,j;
    for(i=0;i<9;i++)
        scanf("%d",&sta[1][i]);
    for(i=0;i<9;i++)
        scanf("%d",&goal[i]);
    int res=bfs();
    if(res==0)
        printf("Impossible\n");
    else
        printf("%d\n",dis[res]);
    return 0;
}
