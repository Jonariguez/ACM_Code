/*
Prim+Heap ��С������
����ע�͵�Tָ����ͼG����С������
����˼�룬Ȼ���Լ�д�ģ�û�뵽1A�ˣ�һ��ʼ���ǻ����Լ���ʵ��������
�Ժ�˼·�����������ã���Ҫ������
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9+9;
int n,m;
int map[maxn][maxn],max_val[maxn][maxn];

struct Edge{
    int a,b,v;
    Edge(int _a=1,int _b=1,int _v=INF):a(_a),b(_b),v(_v){}
    bool operator < (const Edge &e) const {
        return v>e.v;
    }
};

vector<vector<Edge> > G(maxn);
vector<int> save;   //�Ѿ���ӵ�MST�еĵ�

void Input(){
    int i,a,b,v;
    scanf("%d%d",&n,&m);
    memset(map,0,sizeof(map));
    for(i=0;i<=n;i++)
        G[i].clear();
    while(m--){
        scanf("%d%d%d",&a,&b,&v);
        map[a][b]=map[b][a]=v;
        G[a].push_back(Edge(a,b,v));
        G[b].push_back(Edge(b,a,v));
    }
}

int HeapPrim(){
    int i,j,k;
    int vis[maxn],dis[maxn];
    for(i=0;i<=n;i++)
        vis[i]=0,dis[i]=INF;
    int TreeLong=0,tot=0;
    priority_queue<Edge> pq;
    save.clear();
    pq.push(Edge(1,1,0));
    save.push_back(1);
    while(tot<n && !pq.empty()){
        Edge E;
        do{
            E=pq.top();pq.pop();
        }while(vis[E.b]==1 && !pq.empty());
        if(vis[E.b]==0){
            TreeLong+=E.v;vis[E.b]=1;tot++;
            int from=E.a,to=E.b,vv=E.v;
            max_val[from][to]=max_val[to][from]=vv;
            save.push_back(to);         //ע�⣡��Ҫ�Ƚ�to��ӵ�T�У���Ϊ����max_val��ʱ��Ҳ�������£���Ȼ���WA
            for(j=0;j<save.size();j++)
                max_val[j][to]=max_val[to][j]=max(max_val[j][from],max_val[from][to]);  //ע������max_val[][]Ҳ��˫���

            map[from][to]=map[to][from]=0;      //Ҫ����ɾ�ߣ�������ͼ�аѼ�����С������T�ı�ɾ��
            if(tot==n) break;
            for(j=0;j<G[to].size();j++){
                int aa=G[to][j].a,bb=G[to][j].b;
                if(vis[bb]==0){
                    int w=G[to][j].v;
                    if(dis[bb]>w){
                        dis[bb]=w;
                        pq.push(Edge(aa,bb,w));
                    }
                }
            }
        }
    }
    return TreeLong;
}

/*
���ɴ�С����������T��ɾ��һ���ߣ�Ȼ���ټ���һ�����γ�һ���µ������Ǵ�С��������
��СȨֵ�Ϳ��ܵ�����С��ȡֵ�ͣ�����С��Ψһ��
�����ɶ��壬����ӵ������±ߺ�ɾ������ȣ�˵���γɵĴ�С��������������һ������T
����С����������ʱ˵����С��������Ψһ��
���嵽����������˵��Ҫ����ı���a-b������(Ȩֵmap[a][b])����ôӦ��ɾ���ıߵ�Ȩֵ��
��max_val[a][b],�������map[a][b]==max_val[a][b]��˵����С��������Ψһ
*/
bool UniqueJudge(){
    int i,j,flag=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(map[i][j]==0)
                continue;
            if(map[i][j]==max_val[i][j]){   //����޸�һ���߾���
                flag=1;break;
            }
        }
    if(flag)
        return false;
    return true;
}

int main()
{
    int i,j,t,MST;
    scanf("%d",&t);
    while(t--){
        Input();
        MST=HeapPrim();
        if(UniqueJudge())
            printf("%d\n",MST);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
