/****************
*ID:uva816
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=10;
const char* dirs="NESW";
const char* turns="FLR";
//dr和dc也是按上右下左NEWS的顺序来的，这样对应dir_id
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};

int dir_id(char c){
    return strchr(dirs,c)-dirs;
}

int turn_id(char c){
    return strchr(turns,c)-turns;
}

// 站在(r,c)，面朝方向dir(0~3分别表示N, E, S, W)
struct Node{
    int r,c,dir;
    Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

//表示当前状态是(r,c,dir),是否可以沿着转弯方向turn行走。
bool has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node p[maxn][maxn][4];          //p是用来记录当前点的上一步所在点的，用于输出路径，因为每个路口dir不同
int r0,c0,dir,r1,c1,r2,c2;      //对应的turn不同，所以不能单纯的对(r,c)二维判重，还应该加上dir的不同情况

Node walk(const Node& u,int turn){
    int dir=u.dir;
    if(turn==1) dir=(dir+3)%4;  //逆时针 左转L  dir会-1
    if(turn==2) dir=(dir+1)%4;  //顺时针 右转R  dir会+1
    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

bool inside(int r,int c){
    return r>=1 && r<=9 && c>=1 && c<=9;
}

bool input(){
    char s[100],s2[100],s3[100];
    if(scanf("%s%d%d%s%d%d",s3,&r0,&c0,s2,&r2,&c2)!=6) return false;
    printf("%s\n",s3);

    dir=dir_id(s2[0]);
    r1=r0+dr[dir];
    c1=c0+dc[dir];

    memset(has_edge,0,sizeof(has_edge));
    while(true){
        int r,c;
        scanf("%d",&r);
        if(r==0) break;
        scanf("%d",&c);
        while(scanf("%s",s)){
            if(s[0]=='*') break;
            int len=strlen(s);
            for(int i=1;i<len;i++){
                has_edge[r][c][dir_id(s[0])][turn_id(s[i])]=1;
            }
        }
    }

    return true;
}

void print_ans(Node u){
    vector<Node> ans;
    while(true){
        ans.push_back(u);
        if(d[u.r][u.c][u.dir]==0) break;        //初始状态，就是刚刚离开起点，并不是起点，起点是r0，c0
        u=p[u.r][u.c][u.dir];
    }
    ans.push_back(Node(r0,c0,dir));
/*
    int cnt=0;
    for(int i=ans.size()-1;i>=0;i--){
        if(cnt%10==0) printf(" ");      //只要一个空格
        printf(" (%d,%d)",ans[i].r,ans[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(ans.size()%10!=0)
        printf("\n");   */
    reverse(ans.begin(),ans.end());         //reverse(first,last)是直接使用，而不是ans.reverse( )
    for(int i=0;i<ans.size();i++){
        if(i%10==0) printf(" ");
        printf(" (%d,%d)",ans[i].r,ans[i].c);
        if((i+1)%10==0) printf("\n");
    }
    if(ans.size()%10!=0)
        printf("\n");
}

void solve(){
    queue<Node> que;
    memset(d,-1,sizeof(d));
    Node u(r1,c1,dir);
    d[u.r][u.c][u.dir]=0;
    que.push(u);
    while(!que.empty()){
        Node u = que.front();que.pop();
        if(u.r==r2 && u.c==c2){             //成功
            print_ans(u); return ;
        }
        for(int i=0;i<3;i++){
            Node v = walk(u,i);     //此时的朝向是u.dir,需要用i方式转，看符不符合has_edge,然后用v判出界
            if(has_edge[u.r][u.c][u.dir][i]==1 && inside(v.r,v.c) && d[v.r][v.c][v.dir]<0){
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                p[v.r][v.c][v.dir]=u;
                que.push(v);              //别忘了把v加进去
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main()
{
    while(input()){
        solve();
    }
    return 0;
}
