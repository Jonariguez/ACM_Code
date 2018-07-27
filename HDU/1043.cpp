/****************
*ID:HDU1043
*Auth:Jonariguez
*****************
八数码问题
3种hash法
①康托展开   中
②hash函数   快
③STL集合    慢
和poj1077一样
这个题其实答案不唯一，因为我这个一开始和样例
输出不一样的，但是是对的，我还调了半天。。。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef int State[10];

const int maxn=1000000+10;
State sta[maxn],goal;
int dis[maxn];

struct pp{
    int v,pa;
}step[maxn];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
const char* turns="rdlu";   //turns与dx和dy是对应着的，0时对应右，1时对应下。。。。。

void print(int p){
    if(step[p].pa!=-1){
        print(step[p].pa);
        printf("%c",turns[step[p].v]);
    }
}

const int hashsize=1000003;
int head[hashsize],Next[maxn];

void init_table(){
    memset(head,0,sizeof(head));
}

int Hash(State& s){
    int v=0;
    for(int i=0;i<9;i++)
        v=v*10+s[i];
    return v%hashsize;
}

int insert_table(int s){
    int h=Hash(sta[s]);
    int u=head[h];
    while(u){
        if(memcmp(sta[u],sta[s],sizeof(sta[s]))==0) return 0;
        u=Next[u];
    }
    Next[s]=head[h];
    head[h]=s;
    return 1;
}

int bfs(){
    int front=1,rear=2;
    init_table();
    step[1].pa=-1;
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
            step[rear].v=i;
            step[rear].pa=front;
            int newp=xx*3+yy;               //由xx行yy列，转换成newp编号[0,9)
            State& u = sta[rear];
            memcpy(&u,&s,sizeof(s));        //不要忘了把s复制到u
            u[newp]=s[p];               //交换
            u[p]=s[newp];
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
    char ch;
    i=0;
    while(scanf("%c",&ch)!=EOF){
        if(ch==' ' || ch=='\n') continue;
        if(ch=='x')
            sta[1][i++]=0;
        else
            sta[1][i++]=ch-'0';
        if(i%9==0){
            for(i=0;i<9;i++)
                goal[i]=i+1;
            goal[8]=0;
            int res=bfs();
            if(res==0)
                printf("unsolvable\n");
            else{
                print(res);
                printf("\n");
            }
            i=0;
        }
    }
    return 0;
}
