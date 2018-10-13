/****************
*PID:bzoj1015
*Auth:Jonariguez
*****************
���ߣ�����������ɾ���ڵ���������ӽڵ�������ɡ�
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=400000+10;
const int MOD=1e9+7;

int head[maxn],nxt[maxn],vv[maxn],e=1;
int node[maxn],vis[maxn],par[maxn],res[maxn];
bool del[maxn];

void Init(int n){
    for(int i=0;i<=n;i++)
        par[i]=i;
    e=1;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v)))
        return false;
    par[u]=v;
    return true;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

int main()
{
    int i,j,n,m;
    memset(del,0,sizeof(del));
    scanf("%d%d",&n,&m);
    Init(n);
    int x,y;
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        x++;y++;
        add(x,y);add(y,x);
    }
    int K;
    scanf("%d",&K);
    for(i=1;i<=K;i++){
        scanf("%d",&node[i]);
        node[i]++;
        del[node[i]]=1;     //��ɾ���Ľڵ���
    }
    res[K+1]=n-K;
    for(i=1;i<=n;i++){  //�Ⱥ��Ե������Ѿ�ɾ���Ľ�㣬��ʣ�µĽ�㹹������յ�ͼ��Ȼ������յ�ͼ���������Щ��ɾ�����ĵ�
        if(del[i]) continue;
        for(j=head[i];j;j=nxt[j]){
            int v=vv[j];
            if(del[v]) continue;
            if(Union(i,v))
                res[K+1]--;
        }
    }

    for(i=K;i>=1;i--){
        int u=node[i],cnt=-1;
        for(j=head[u];j;j=nxt[j]){
            int v=vv[j];
            if(del[v]) continue;    //����ǻ�û����ӵ�ͼ�еľͺ���
            int f=find(v);
            if(f!=u)    //�������vis[f]!=i����ǵģ������ڲ�Union�������Ҫ�����cnt��Ȼ�����һ�����е�v��ȥUnion
                cnt++;      //�ʸ���Union�����й̶���par[u]=v,��������f!=u�����жϡ�
            //vis[f]=i;
            Union(f,u);
        }
        del[u]=0;   //�������ӵ�ͼ��֮��ȥ����ɾ�������
        res[i]=res[i+1]-cnt;
    }
    for(i=1;i<=K+1;i++)
        printf("%d\n",res[i]);
    return 0;
}



