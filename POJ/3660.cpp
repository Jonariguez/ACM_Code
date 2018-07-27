/****************
*PID:poj3660
*Auth:Jonariguez
*****************
��ţ֮���������ϵ��������floyd�󴫵ݱհ���ȷ��ÿ��ͷţ
֮��Ĺ�ϵ��Ȼ�����ÿ��ţ�Ķȡ�
�������һͷţ��Ӯ����ţ�ĸ������ϰܸ�����ţ�ĸ���=n-1����
��rank��ȷ����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9;
int mp[maxn][maxn],n,m,d[maxn];

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(mp,0,sizeof(mp));
        memset(d,0,sizeof(d));
        int a,b;
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
           // d[b]++;
        }
        for(int k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(mp[i][k] && mp[k][j])
                        mp[i][j]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(mp[i][j]){
                    d[i]++;d[j]++;
                }
        int res=0;
        for(i=1;i<=n;i++)
            if(d[i]==n-1) res++;
        printf("%d\n",res);
    }
    return 0;
}

