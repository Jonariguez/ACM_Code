/****************
*PID:bzoj1016
*Auth:Jonariguez
*****************
https://blog.csdn.net/sdfzyhx/article/details/52075151
�������ĳ�����в�ͬ����С����������ôÿ�������ı�Ȩ����һ����
��ÿ��Ȩֵ���ֵĴ���һ����
����˵��ÿ�������ı�Ȩ�ŵ�����������֮��õ���������һ���ġ�
����kruskal�㷨��˼�룬���ȿ��Ǳ�ȨС�ıߣ�Ȼ����̸��ĳһ��Ȩֵ������£�
����С�ı��ܼӵ���������Ķ��ӽ�ȥ�ˣ�������С��Ȩ�ıߵ�Ӱ�졣
������㷨�����δ���ÿ�ֱ�Ȩ(��С����)��Ϊʲô�ܹ������Ĵ���ÿ�ֱ�Ȩ��
��Ϊ����������ͨ�飬�����������Ȩֵ����ȵı�a,b,w[a]<w[b]ͬʱ������������ͨ�飬
�����Ը���kruskal�㷨����ѡ��a��������aʱ���ÿ���b�����ڴ���bʱa�Ѿ��ӵ�����������ȥ�ˣ�
֮ǰ��������ͨ���Ѿ��ϲ���һ����ͨ�飬b��Ȼû�����塣
���ڴ���Ȩֵ��ı�ʱ��ͨ���״̬�ʹ���ȨֵС�ı�ʱ��״̬���������Կ��Զ������㡣
����ó˷�ԭ���ɡ�
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

const int maxn=100+10;
const int maxm=1000+10;
const int MOD=31011;

int par[maxn];

struct edge{
    int a,b,w,cnt;
}s[maxm];

int cmp(const edge &x,const edge &y){
    return x.w<y.w;
}

int find(int x){
    return par[x]==x?x:find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v)))
        return false;
    par[u]=v;
    return true;
}

int sum;

void dfs(int cur,int End,int cnt,int C){
    if(cur>=End) {
        if(cnt==C)
            sum++;
        return ;
    }
    int fa=find(s[cur].a),fb=find(s[cur].b);
    dfs(cur+1,End,cnt,C);
    if(fa!=fb){
        par[fa]=fb;
        dfs(cur+1,End,cnt+1,C);
        par[fa]=fa;par[fb]=fb;
    }
}


int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);
        s[i].cnt=0;
    }
    sort(s+1,s+m+1,cmp);
    for(i=1;i<=n;i++)
        par[i]=i;
    int tot=0,all=0;
    for(i=1;i<=m;){
        j=i;
        while(j<=m && s[j].w==s[i].w){
            if(Union(s[j].a,s[j].b)){
                s[i].cnt++;all++;
            }
            j++;
        }
        i=j;
    }
    if(all!=n-1){
        puts("0");return 0;
    }
    for(i=1;i<=n;i++)
        par[i]=i;
    LL res=1;
    for(i=1;i<=m;){
        j=i;
        while(s[j].w==s[i].w) j++;
        sum=0;
        dfs(i,j,0,s[i].cnt);
        res*=sum;
        res%=MOD;
        for(int k=i;k<j;k++)
            Union(s[k].a,s[k].b);
        i=j;
    }
    printf("%lld\n",res);
    return 0;
}



