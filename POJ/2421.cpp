/*
MST-kruskal
��ʵ�����ڸ���һ���ֱߵ�����£�������С���������϶�����������MST
��������Ҫ����Ҫ���Ѿ������ıߣ�Ȼ������MST-�Ѹ����ıߵĳ��Ⱥ�=��
Ϊʲô���ǲ�������Щ��֪��ȥ����С���������Ǳ���Ҫ������Щ������Ľ��
�����Ž⡣����ȷ���ǿ���֤���ģ�
�����������һ����e������a��b�����������С������T�У��ȼٶ�û�������ߣ���ôa
��b�ֱ���������ͨ����A��B���ô����A��Bֻ����e���������ţ���Ϊ�������߲�
��Ǯ��������ӱ�ı�������A��B�Ļ�����ô�±�eСҲҪ�л��ѵġ�
������Ҳ��������
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=110;
int vis[maxn][maxn],n,q;

struct pp{
    int a,b,v;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

typedef struct UFSet{
    int par[maxn];
    void Init(){ for(int i=0;i<maxn;i++) par[i]=i; }
    int Find(int x){ return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[v]=u;
        return true;
    }
}UFSet;

UFSet ss;
int cnt,tot;

void Kruskal_Input(){
    int i,j;
    scanf("%d",&n);
    ss.Init();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&vis[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++){
            s[tot].a=i;s[tot].b=j;s[tot++].v=vis[i][j];
        }
    scanf("%d",&q);
    cnt=0;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(ss.Union(x,y))
            cnt++;
    }
    sort(s,s+tot,cmp);
}

int Kruskal(){
    int i,j,TreeLong=0;
    for(i=0;i<tot;i++){
        if(ss.Union(s[i].a,s[i].b)){
            TreeLong+=s[i].v;
            if(++cnt==n-1) break;
        }
    }
    return TreeLong;
}

int main()
{
    Kruskal_Input();
    printf("%d\n",Kruskal());
    return 0;
}
