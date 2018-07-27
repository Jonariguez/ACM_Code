/****************
*PID:poj3268
*Auth:Jonariguez
*****************
������x�����������̾��룬��Dij
Ȼ�����еı߷�������Dij����ÿ���㵽x�����·
����d�����Ӧ�ĵ�ĺ͵����ֵ���Ǵ𰸡�
mp[0]��ԭͼ��mp[1]�Ƿ����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1e9;
int mp[2][maxn][maxn],d[2][maxn],vis[maxn],n,m,x;

void Dij(int t){
    memset(vis,0,sizeof(vis));
    d[t][x]=0;
    int i;
    for(i=1;i<=n;i++)
        d[t][i]=mp[t][x][i];
    vis[x]=1;
    while(1){
        int v=-1;
        for(i=1;i<=n;i++){
            if(vis[i]==0 && (v==-1 || d[t][v]>d[t][i]))
                v=i;
        }
        if(v==-1) break;
        vis[v]=1;
        for(i=1;i<=n;i++){
            if(mp[t][v][i]<INF && d[t][i]>d[t][v]+mp[t][v][i])
                d[t][i]=d[t][v]+mp[t][v][i];
        }
    }
}


int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&x);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            mp[0][i][j]=mp[1][i][j]=INF;
        }
        d[0][i]=d[1][i]=INF;
    }
    for(i=1;i<=n;i++) mp[0][i][i]=mp[1][i][i]=0;    //һ��Ҫ�������ʼ������ȻWA
    for(i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        mp[0][a][b]=c;mp[1][b][a]=c;
    }
    Dij(0);
    Dij(1);
    int res=0;
    for(i=1;i<=n;i++)
        res=max(res,d[0][i]+d[1][i]);
    printf("%d\n",res);
    return 0;
}
