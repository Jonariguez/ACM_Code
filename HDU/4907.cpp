/****************
*PID:hdu4907
*Auth:Jonariguez
*****************
�Ӻ���ǰԤ�����ÿ��ʱ����ܹ�����������ʱ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+5;
int t[maxn],a[maxn];

int main()
{
    int i,j,n,res,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        int x;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            a[x]=1;
        }
        int last=200001;    //ע��Ҫ����200001,������ÿ����������ֵ+1
        for(i=200001;i>=1;i--){
            if(a[i]==0){
                t[i]=i;last=i;
            }else
                t[i]=last;
        }
        while(m--){
            scanf("%d",&x);
            printf("%d\n",t[x]);
        }
    }
    return 0;
}
