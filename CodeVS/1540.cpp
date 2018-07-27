/****************
*PID:cdvs1540
*Auth:Jonariguez
*****************
��Ȩ���鼯
ά����Ϣ�����Ϊx��ս���ڸ�ս�������е�ǰ���ս����Ŀ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
int par[maxn],sum[maxn],under[maxn];

int find(int x){
    if(x==par[x]) return x;
    int y=find(par[x]);
    under[x]+=under[par[x]];
    return par[x]=y;
}

void Union(int u,int v){
    u=find(u);v=find(v);
    par[u]=v;
    under[u]+=sum[v];
    sum[v]+=sum[u];     //ע���������䲻�ܵߵ�
}

int main()
{
    int i,j,n,T;
    for(i=1;i<=30000;i++){
        par[i]=i;sum[i]=1;under[i]=0;
    }
    char str[4];
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%s%d%d",str,&a,&b);
        if(str[0]=='M')
            Union(a,b);
        else {
            int fa=find(a),fb=find(b);
            if(fa!=fb)
                printf("-1\n");
            else printf("%d\n",abs(under[a]-under[b])-1);
        }
    }
    return 0;
}

