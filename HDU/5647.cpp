/****************
*PID:5647
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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

const int maxn=200000+10;
const LL MOD=1e9+7;
LL sizeOfSubtree[maxn];//��ʾ��iΪ���ڵ�����п��ܵ�������С֮��
LL wayOfSubtree[maxn];//��ʾ��iΪ���ڵ����������
vector<int> con[maxn];

void add(int u,int v){
    con[u].push_back(v);
}

void dfs(int u,int pa){
    sizeOfSubtree[u]=1;
    wayOfSubtree[u]=1;
    for(int i=con[u].size()-1;i>=0;i--){
        int v=con[u][i];
        if(v==pa) continue;
        dfs(v,u);
        ///��ǰ������u��ǰ[0,i-1]�������ܹ���������СΪsizeOfSubtree[u],���ڵ�i������u�ĳ��֣�
        ///��ô��v����ѡһ��������ʽ����ǰ[0,i-1]�γ�����������ѡwayOfSubtree[v]�֣������Ļ���
        ///ʹsizeOfSubtree[u]����wayOfSubtree[v]����������wayOfSubtree[v]����ע�⣡�����ﲢû��
        ///ͬʱ�ѵ�i������v��size���ȥ��ֻ�ǰ�֮ǰ[0,i-1]���ټ�wayOfSubtree[v]����
        sizeOfSubtree[u]=sizeOfSubtree[u]+sizeOfSubtree[u]*wayOfSubtree[v];
        ///���������i������v��size������ô���أ������Ѿ�֪������v�����п��������Ĵ�С֮��sizeOfSubtree[v]��
        ///��ô����sizeOfSubtree[u]�Ĺ����Ƕ����أ���sizeOfSubtree[v]�ᱻ�㼸���أ�
        ///�������ǣ����ǿ���ǰ��uΪ���������ķ�����wayOfSubtree[u]������ÿһ�ַ�����ֻ��Ҫ��(u,v)���ӣ�
        ///��ôsizeOfSubtree[v]��Ҫ���ۼ�һ�Σ����ۼ�wayOfSubtree[u]�Ρ�
        ///(���� ����uΪ���ķ�����ȡ��1�ַ���  ---- ����vΪ���ķ���ȡһ��->��sizeOfSubtree[v]���ڵ�
        ///      ����uΪ���ķ�����ȡ��2�ַ���  ---- ����vΪ���ķ���ȡһ��->��sizeOfSubtree[v]���ڵ�
        /// .....����uΪ���ķ�����ȡ��wayOfSubtree[u]�ַ���  ---- ����vΪ���ķ���ȡһ��->��sizeOfSubtree[v]���ڵ�
        ///�ʹ�wayOfSubtree[u]����
        sizeOfSubtree[u]=sizeOfSubtree[u]+wayOfSubtree[u]*sizeOfSubtree[v];
        sizeOfSubtree[u]%=MOD;
        wayOfSubtree[u]=wayOfSubtree[u]*(wayOfSubtree[v]+1)%MOD;
    }
}

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) con[i].clear();
        if(n==1){
            puts("1");continue;
        }
        for(i=2;i<=n;i++){
            int a;
            scanf("%d",&a);
            add(a,i);
        }
        dfs(1,-1);
        LL res=0;
        for(i=1;i<=n;i++){
            res+=sizeOfSubtree[i];
            res%=MOD;
        }
        printf("%I64d\n",res);
    }
    return 0;
}


