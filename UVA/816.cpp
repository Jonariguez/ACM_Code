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
//dr��dcҲ�ǰ���������NEWS��˳�����ģ�������Ӧdir_id
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};

int dir_id(char c){
    return strchr(dirs,c)-dirs;
}

int turn_id(char c){
    return strchr(turns,c)-turns;
}

// վ��(r,c)���泯����dir(0~3�ֱ��ʾN, E, S, W)
struct Node{
    int r,c,dir;
    Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

//��ʾ��ǰ״̬��(r,c,dir),�Ƿ��������ת�䷽��turn���ߡ�
bool has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node p[maxn][maxn][4];          //p��������¼��ǰ�����һ�����ڵ�ģ��������·������Ϊÿ��·��dir��ͬ
int r0,c0,dir,r1,c1,r2,c2;      //��Ӧ��turn��ͬ�����Բ��ܵ����Ķ�(r,c)��ά���أ���Ӧ�ü���dir�Ĳ�ͬ���

Node walk(const Node& u,int turn){
    int dir=u.dir;
    if(turn==1) dir=(dir+3)%4;  //��ʱ�� ��תL  dir��-1
    if(turn==2) dir=(dir+1)%4;  //˳ʱ�� ��תR  dir��+1
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
        if(d[u.r][u.c][u.dir]==0) break;        //��ʼ״̬�����Ǹո��뿪��㣬��������㣬�����r0��c0
        u=p[u.r][u.c][u.dir];
    }
    ans.push_back(Node(r0,c0,dir));
/*
    int cnt=0;
    for(int i=ans.size()-1;i>=0;i--){
        if(cnt%10==0) printf(" ");      //ֻҪһ���ո�
        printf(" (%d,%d)",ans[i].r,ans[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(ans.size()%10!=0)
        printf("\n");   */
    reverse(ans.begin(),ans.end());         //reverse(first,last)��ֱ��ʹ�ã�������ans.reverse( )
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
        if(u.r==r2 && u.c==c2){             //�ɹ�
            print_ans(u); return ;
        }
        for(int i=0;i<3;i++){
            Node v = walk(u,i);     //��ʱ�ĳ�����u.dir,��Ҫ��i��ʽת������������has_edge,Ȼ����v�г���
            if(has_edge[u.r][u.c][u.dir][i]==1 && inside(v.r,v.c) && d[v.r][v.c][v.dir]<0){
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                p[v.r][v.c][v.dir]=u;
                que.push(v);              //�����˰�v�ӽ�ȥ
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
