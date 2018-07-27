/*
BIT
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn=100000+10;
int bit[maxn*2],vis[maxn],lowbit[maxn*2],n,ncnt;   //��Ϊÿ���ڵ���Start[],End[]����������bit�нڵ���maxn�Ķ���

int Lowbit(int i){
    if(lowbit[i]!=-1)
        return lowbit[i];
    return lowbit[i]=i&(-i);
}

void add(int i,int v){
    while(i<=ncnt){
        bit[i]+=v;
        i+=Lowbit(i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=Lowbit(i);
    }
    return res;
}

//vector<int> G[maxn];
vector<vector<int> > G(maxn);   //Ϊʲô��������ʱ��������ͳ�ʱ�أ�(Ӧ�����ڶ�ά�϶��Ǳ䳤���飬��������ֻ��һά)
int Start[maxn],End[maxn];

void dfs(int x){
    Start[x]=++ncnt;
    for(int i=0;i<G[x].size();i++)
        dfs(G[x][i]);
    End[x]=++ncnt;
}


int main()
{
    int i,j,m,a,b,x;
    char op[3];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
    }
    ncnt=0;
    dfs(1);
    memset(lowbit,-1,sizeof(lowbit));
 //   for(i=1;i<=n;i++)
  //      printf("%d %d\n",Start[i],End[i]);
 //   for(i=1;i<=ncnt;i++)        //ע��������ncnt
 //       add(i,1);
    for(i=1;i<=ncnt;i++)          //�����Ż�
        bit[i]=i-(i-Lowbit(i));
    scanf("%d",&m);
    while(m--){
        scanf("%s%d",op,&x);
        if(op[0]=='C'){
            if(vis[x]==0){
                add(Start[x],-1);add(End[x],-1);
                vis[x]=1;
            }else{
                add(Start[x],1);add(End[x],1);
                vis[x]=0;
            }
        }else{
            int t1=sum(Start[x]-1),t2=sum(End[x]);
            printf("%d\n",(t2-t1)/2);
        }
    }
    return 0;
}
