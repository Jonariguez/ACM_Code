/****************
*PID:cdvs1506
*Auth:Jonariguez
*****************
��Ϊ�����˸��ӹ�ϵ��һ·ͬʱ���ϲ���¼����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int par[maxn],vis[maxn];

int find(int x){
    while(x!=par[x])
        x=par[x];
    return x;
}

void Union(int u,int v){
    if((u=find(u))!=(v=find(v)))
        par[v]=u;
}

int main()
{
    int i,j,n,a,b;
    while(scanf("%d",&n)!=EOF){
      //  for(i=0;i<=n;i++)
      //      par[i]=i;
        par[1]=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<n;i++){
            scanf("%d%d",&a,&b);
          //  Union(a,b);
            par[b]=a;
        }
        scanf("%d%d",&a,&b);
        if(a==b){
            printf("%d\n",a);continue;
        }
        int res;
        vis[a]=vis[b]=1;
        while(1){
            if(a!=1){
                a=par[a];
                if(vis[a]){
                    res=a;break;
                }
                vis[a]=1;
            }
            if(b!=1){
                b=par[b];
                if(vis[b]){
                    res=b;break;
                }
                vis[b]=1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

