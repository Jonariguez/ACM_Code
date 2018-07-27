/****************
*PID:hdu5627
*Auth:Jonariguez
*****************
̰�ĵشӴ�Сö��ÿһ��λ�����һ��λ��ȡ���ҽ�������Ȩֵ
���λ��Ϊ0�ı����γ�һ����������
�Ƿ����γ����������Ǽ򵥵�bfsһ�¾����ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=300000+10;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],e,n,m,now;
bool vis[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

bool bfs(){
    memset(vis,0,sizeof(vis));
    queue<int> que;
    que.push(1);
    vis[1]=1;
    while(!que.empty()){
        int u=que.front();que.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=vv[i],w=wei[i];
            if(vis[v]==0 && (w&now)==now){
                que.push(v);vis[v]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(vis[i]==0) return false;
    return true;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        int u,v,w;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        int res=0;
        for(i=30;i>=0;i--){
            now=((1<<i)|res);
            if(bfs())
                res=now;
        }
        printf("%d\n",res);
    }
    return 0;
}
