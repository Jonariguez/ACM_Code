/****************
*PID:bzoj1014
*Auth:Jonariguez
*****************
参考：
https://blog.csdn.net/ww140142/article/details/47607625
改成了在pushUp中维护hash值时，采用左子树的权重大
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
typedef unsigned long long LL;
typedef int Ll;
#define seed 131
#define which(x) (chi[par[x]][1]==x)
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

char str[maxn];
int n,root,tot;
LL hash[maxn],fact[maxn];
int Size[maxn],chi[maxn][2],par[maxn];
char s[maxn];

void pushUp(int k){
    Size[k]=Size[chi[k][0]]+Size[chi[k][1]]+1;
    hash[k]=hash[chi[k][1]]+fact[Size[chi[k][1]]]*s[k]+fact[Size[chi[k][1]]+1]*hash[chi[k][0]];
}

void Rotate(int x){     //只定义一次左旋或者右旋，具体整个过程要怎么旋转由splay决定。
    int f=par[x];
    bool k=which(x);
    chi[par[f]][which(f)]=x;
    chi[f][k]=chi[x][!k];
    par[chi[f][k]]=f;
    chi[x][!k]=f;
    par[x]=par[f];
    par[f]=x;

    Size[x]=Size[f];    //旋转过后，节点不变，故Size也不变
    hash[x]=hash[f];    //结点不变，对应的序列不变，那么hash值也不变
    pushUp(f);  //先维护下面的y，在维护上面的x
    //pushUp(x);  //x也要再维护。(其实在这个题可以不维护，因为上面Size[x]=Size[f],hash[x]=hash[f]已经维护过了
                //即两者留一个即可,但放在其他题里就不一定了).
}

void splay(int x,int g){    //将x旋转到g点下面，即以g点为父节点，如果g=0，则说明将x旋转到树根。
    while(par[x]!=g){
        int f=par[x];
        if(par[f]==g){
            Rotate(x);
            break;
        }
        if(which(x)^which(f))
            Rotate(x);
        else
            Rotate(f);
        Rotate(x);  //其实这里直接Rotate(x)两次也对，不知道为什么。。。
    }
    if(!g)  //如果g=0，则说明树根变了，就要更新root=x
        root=x;
}

int Rank(int x,int k){  //在以x为根的树里面找第k小的节点
    if(k<=Size[chi[x][0]])
        return Rank(chi[x][0],k);
    else if(k==Size[chi[x][0]]+1)
        return x;
    else
        return Rank(chi[x][1],k-Size[chi[x][0]]-1);
}

int build(int l,int r,int f){
    if(l>r)
        return 0;
    int x=++tot,m=(l+r)/2;
    par[x]=f;
    s[x]=str[m];
    chi[x][0]=build(l,m-1,x);
    chi[x][1]=build(m+1,r,x);
    pushUp(x);
    return x;
}

void Insert(int k,char val){
    int x=Rank(root,k),y=Rank(root,k+1);
    splay(x,0);     //将x旋转到树根
    splay(y,x);     //将y旋转到以x为根
    s[++tot]=val;   //添加新节点
    par[tot]=y;chi[y][0]=tot;    //放在y的左孩子上
    pushUp(tot);
    pushUp(y);
    pushUp(x);
}

void Change(int k,char val){
    int x=Rank(root,k);
    splay(x,0);     //将x旋转到根节点之后直接修改即可
    s[x]=val;
    pushUp(x);
}

int LCQ(int kx,int ky){
    int l=0,r=n,m;
    while(l<=r){
        m=(l+r)/2;
        if(ky+m>n+2){   //长度太长了，不符合
            r=m-1;
            continue;
        }
        int x=Rank(root,kx-1),y=Rank(root,kx+m);
        splay(x,0);
        splay(y,x);
        LL tempx=hash[chi[y][0]];
        x=Rank(root,ky-1);y=Rank(root,ky+m);
        splay(x,0);
        splay(y,x);
        LL tempy=hash[chi[y][0]];
        if(tempx==tempy)
            l=m+1;
        else
            r=m-1;
    }
    return r;
}

int main()
{
    int i,j,k,M;
    //初始化
    tot=0;
    scanf("%s%d",str+1,&M);
    n=strlen(str+1);
    fact[0]=1;
    for(i=1;i<=100000;i++)
        fact[i]=fact[i-1]*seed;
    root=build(0,n+1,0);
    char op[3];
    for(i=1;i<=M;i++){
        char va[3];
        int x,y;
        scanf("%s",op);
        if(op[0]=='I'){
            scanf("%d%s",&x,va);
            Insert(x+1,va[0]);
            n++;
        }else if(op[0]=='R'){
            scanf("%d%s",&x,va);
            Change(x+1,va[0]);

        }else{
            scanf("%d%d",&x,&y);
            if(x>y)
                swap(x,y);
            if(x!=y)
                printf("%d\n",LCQ(x+1,y+1));
            else
                printf("%d\n",n-x+1);
        }
    }
    return 0;
}


