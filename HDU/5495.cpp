/****************
*PID:hdu5495
*Auth:Jonariguez
*****************
�û�Ⱥ
�ؼ���������1~n�����У����Ա�Ȼa[],b[]������ͬ�����֣�
Ҳ����һ������һЩѭ������ɣ���ÿ��ѭ���ھ�������
��β���һ������ֻ���һλ����������յ�LCSҲ����
�ܳ���ȥѭ���ڵĸ����������Ի����������ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn],b[maxn],c[maxn],vis[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            c[a[i]]=b[i];
        }
        int res=n;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                int x=i;
                if(c[x]!=x) res--;      //c[x]!=x�����Ի�
                while(!vis[x]){
                    vis[x]=1;
                    x=c[x];
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
