/****************
*PID:
*Auth:Jonariguez
*****************
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
#include <cstdlib>
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

const int maxn=20000+10;
const int maxm=60000+10;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

struct Node{
    Node *chi[2];
    int r;
    int v;
    int s;
    Node(int v):v(v){ chi[0]=chi[1]=NULL;r=rand();s=1;}
    bool operator < (const Node& rhs) const {
        return r<rhs.r;
    }
    int cmp(int x) const {
        if(x==v) return -1;
        return x<v?0:1;
    }
    void update(){
        s=1;
        if(chi[0]!=NULL) s+=chi[0]->s;
        if(chi[1]!=NULL) s+=chi[1]->s;
    }
};

void Rotate(Node* &o,int d){
    Node* k=o->chi[d^1];
    o->chi[d^1]=k->chi[d];
    k->chi[d]=o;
    o->update();k->update();
    o=k;
}

void Insert(Node* &o,int x){
    if(o==NULL) o=new Node(x);
    else {
        int d=(x < o->v ? 0:1);
        Insert(o->chi[d],x);
        if(o->chi[d]->r > o->r)
            Rotate(o,d^1);
    }
    o->update();
}

void Delete(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
        Node* u=o;
        if(o->chi[0]!=NULL && o->chi[1]!=NULL){
            int d2=(o->chi[0]->r > o->chi[1]->r ?1:0);
            Rotate(o,d2);
            Delete(o->chi[d2],x);
        }else {
            if(o->chi[0] == NULL)
                o=o->chi[1];
            else o=o->chi[0];
            delete u;
        }
    }else Delete(o->chi[d],x);
    if(o!=NULL) o->update();
}

int kth(Node* o,int k){
    if(o==NULL || k<=0 || k > o->s) return 0;
    int s=(o->chi[1] == NULL?0:o->chi[1]->s);
    if(k==s+1) return o->v;
    else if(k<=s) return kth(o->chi[1],k);
    else return kth(o->chi[0],k-s-1);
}

void Merge(Node* &src,Node* &dest){
    if(src->chi[0]!=NULL) Merge(src->chi[0],dest);
    if(src->chi[1]!=NULL) Merge(src->chi[1],dest);
    Insert(dest,src->v);
    delete src;
    src=NULL;
}

void removetree(Node* o){
    if(o->chi[0]!=NULL) removetree(o->chi[0]);
    if(o->chi[1]!=NULL) removetree(o->chi[1]);
    delete o;
    o=NULL;
}

Node* root[maxn];

typedef struct UFSET{
    int par[maxn];
    void Init(int n){
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int Find(int x){
        return par[x]==x?x:par[x]=Find(par[x]);
    }
}ufset;

ufset uset;

int val[maxn];
bool del[maxm];

struct Edge{
    int a,b;
}s[maxm];

struct Command{
    char type;
    int x,p;
}com[500005];

int main()
{
    int i,j,n,m,kcase=1;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=1;i<=m;i++)
            scanf("%d%d",&s[i].a,&s[i].b);
        char o[5];
        int comCnt=0;
        memset(del,0,sizeof(del));
        while(scanf("%s",o)){
            if(o[0]=='E') break;
            com[++comCnt].type=o[0];
            if(o[0]=='D'){
                scanf("%d",&com[comCnt].x);
                del[com[comCnt].x]=1;
            }
            else {
                scanf("%d%d",&com[comCnt].x,&com[comCnt].p);
                if(o[0]=='C'){
                    int temp=com[comCnt].p;
                    com[comCnt].p=val[com[comCnt].x];
                    val[com[comCnt].x]=temp;
                }
            }
        }
        uset.Init(n);
        for(i=1;i<=n;i++){
            if(root[i]!=NULL)
                removetree(root[i]);
            root[i]=new Node(val[i]);
        }
        for(i=1;i<=m;i++){
            if(del[i]) continue;
            int u=uset.Find(s[i].a);
            int v=uset.Find(s[i].b);
            if(u==v) continue;
            if(root[u]->s < root[v]->s){
                Merge(root[u],root[v]);
                uset.par[u]=v;
            }else {
                Merge(root[v],root[u]);
                uset.par[v]=u;
            }
        }
        int querycnt=0;
        LL res=0;
        for(i=comCnt;i>=1;i--){
            if(com[i].type=='D'){
                int u=uset.Find(s[com[i].x].a);
                int v=uset.Find(s[com[i].x].b);
                if(u==v) continue;
                if(root[u]->s < root[v]->s){
                    Merge(root[u],root[v]);
                    uset.par[u]=v;
                }else {
                    //puts("!!!");
                    Merge(root[v],root[u]);
                    uset.par[v]=u;
                }
            }else if(com[i].type=='C'){
                int u=uset.Find(com[i].x);
                Delete(root[u],val[com[i].x]);
                Insert(root[u],com[i].p);
                val[com[i].x]=com[i].p;
            }else {
                int u=uset.Find(com[i].x);
                res+=kth(root[u],com[i].p);
                querycnt++;
            }
        }
        printf("Case %d: %.6f\n",kcase++,1.0*res/querycnt);
    }
    return 0;
}

