/*
dfs��Ȼ��Ա��������յ��ж��Ƿ���'X'���ɡ�
һֱTLE��Ȼ������д�����if���жϵ�ǰ��
���յ��λ�ù�ϵ��Ȼ����ѡ�����ŵķ�������
dfs��û�뵽�������һ����TLE��
��Ϊ�����ֻ��ݣ�500*500��̫���ˡ�
�н��ۣ���дdfsʱӦ��ע���й��ĵ��ڻ���ʱ
������Ҫ�Ļء�.������Ϊ����ǰ��·�����Ǵ���
�ģ���ȷ�͵����ˣ�������Ҫ�ٴӱ��·������
���ж�һ�Ρ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=500+10;
char a[maxn][maxn];
int n,m,vis[maxn][maxn];
int r1,c1,r2,c2,yes;
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

void dfs(int r,int c){
    if(yes) return ;
    for(int i=0;i<4;i++){
        int rr=r+dr[i],cc=c+dc[i];
        if(rr<1 || rr>n || cc<1 || cc>m) continue;
        if(rr==r2 && cc==c2 && a[rr][cc]=='X'){
            yes=1;return ;
        }
        if(a[rr][cc]=='.'){
            a[rr][cc]='X';
         //   printf("rr=%d,cc=%d\n",rr,cc);
            dfs(rr,cc);
          //  a[rr][cc]='.';
        }
    }
}

bool check(int x,int y){
    if(x<1 || x>n || y<1 || y>m)
        return false;
    return true;
}

bool succ(int x,int y){
    if(x==r2 && y==c2 && a[x][y]=='X')
        return true;
    return false;
}


int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf(" %c",&a[i][j]);
            }
        }
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        yes=0;
        dfs(r1,c1);
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


/*
void dfs1(int r,int c){
    if(yes) return ;
    if(r2<r){
        if(c2<c){
            if(succ(r-1,c)){yes=1;return ;}
            if(check(r-1,c) && a[r-1][c]=='.'){
                a[r-1][c]='X';
                dfs(r-1,c);
                a[r-1][c]='.';
            }
            if(succ(r,c-1)){yes=1;return ;}
            if(check(r,c-1) && a[r][c-1]=='.'){
                a[r][c-1]='X';
                dfs(r,c-1);
                a[r][c-1]='.';
            }
            if(succ(r,c+1)){yes=1;return ;}
            if(check(r,c+1) && a[r][c+1]=='.'){
                a[r][c+1]='X';
                dfs(r,c+1);
                a[r][c+1]='.';
            }
            if(succ(r+1,c)){yes=1;return ;}
            if(check(r+1,c) && a[r+1][c]=='.'){
                a[r+1][c]='X';
                dfs(r+1,c);
                a[r+1][c]='.';
            }
        }else {
            if(succ(r-1,c)){yes=1;return ;}
            if(check(r-1,c) && a[r-1][c]=='.'){
                a[r-1][c]='X';
                dfs(r-1,c);
                a[r-1][c]='.';
            }
            if(succ(r,c+1)){yes=1;return ;}
            if(check(r,c+1) && a[r][c+1]=='.'){
                a[r][c+1]='X';
                dfs(r,c+1);
                a[r][c+1]='.';
            }
            if(succ(r,c-1)){yes=1;return ;}
            if(check(r,c-1) && a[r][c-1]=='.'){
                a[r][c-1]='X';
                dfs(r,c-1);
                a[r][c-1]='.';
            }
            if(succ(r+1,c)){yes=1;return ;}
            if(check(r+1,c) && a[r+1][c]=='.'){
                a[r+1][c]='X';
                dfs(r+1,c);
                a[r+1][c]='.';
            }
        }
    }else {
        if(c2<c){
            if(succ(r+1,c)){yes=1;return ;}
            if(check(r+1,c) && a[r+1][c]=='.'){
                a[r+1][c]='X';
                dfs(r+1,c);
                a[r+1][c]='.';
            }
            if(succ(r,c-1)){yes=1;return ;}
            if(check(r,c-1) && a[r][c-1]=='.'){
                a[r][c-1]='X';
                dfs(r,c-1);
                a[r][c-1]='.';
            }
            if(succ(r,c+1)){yes=1;return ;}
            if(check(r,c+1) && a[r][c+1]=='.'){
                a[r][c+1]='X';
                dfs(r,c+1);
                a[r][c+1]='.';
            }
            if(succ(r-1,c)){yes=1;return ;}
            if(check(r-1,c) && a[r-1][c]=='.'){
                a[r-1][c]='X';
                dfs(r-1,c);
                a[r-1][c]='.';
            }
        }else {
            if(succ(r+1,c)){yes=1;return ;}
            if(check(r+1,c) && a[r+1][c]=='.'){
                a[r+1][c]='X';
                dfs(r+1,c);
                a[r+1][c]='.';
            }
            if(succ(r,c+1)){yes=1;return ;}
            if(check(r,c+1) && a[r][c+1]=='.'){
                a[r][c+1]='X';
                dfs(r,c+1);
                a[r][c+1]='.';
            }
            if(succ(r,c-1)){yes=1;return ;}
            if(check(r,c-1) && a[r][c-1]=='.'){
                a[r][c-1]='X';
                dfs(r,c-1);
                a[r][c-1]='.';
            }
            if(succ(r-1,c)){yes=1;return ;}
            if(check(r-1,c) && a[r-1][c]=='.'){
                a[r-1][c]='X';
                dfs(r-1,c);
                a[r-1][c]='.';
            }
        }
    }
}
*/
