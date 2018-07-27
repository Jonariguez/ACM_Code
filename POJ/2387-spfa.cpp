/*
���·��spfa�㷨 �������Ӷȣ�O(E)   32ms(dijksral+heap:=47ms)
��һ��дspfa����ǰ��֪��ʱ��Ϊ�Ƕิ�Ӷ�nb���㷨��
��ʵ����Bellman-ford�㷨�ĸĽ���ÿ�β�����äĿ��
�����еĵ�ı߽����жϲ��ɳڣ����Ƕ���Щ�ϴ����ɳ�
��dis�ı�ĵ�����ɳڣ���Щ����һ������ά������
��Dijkstra+heap��Ҫ��
*/
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int maxn=1000+10;
const int inf=2000000;

int n,m,map[maxn][maxn],vis[maxn],dis[maxn];

void Input(){
    int i,j,a,b,c;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            map[i][j]=inf;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(map[a][b]>c)
            map[a][b]=map[b][a]=c;
    }
}

int spfa(int s,int e){
    int i;
    memset(vis,0,sizeof(vis));
    fill(dis,dis+n+1,inf);
    dis[s]=0;vis[s]=1;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int t=que.front();que.pop();
        for(i=1;i<=n;i++)
            if(map[t][i]<inf && dis[i]>dis[t]+map[t][i]){
                dis[i]=dis[t]+map[t][i];
                que.push(i);
            }
    }
    return dis[e];
}

int main()
{
    Input();
    printf("%d\n",spfa(n,1));
    return 0;
}
