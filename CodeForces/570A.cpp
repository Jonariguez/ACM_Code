/****************
*ID:cf570A
*Auth:Jonariguez
*****************
�����ͬʱ�����򣬰ѵ�һ��city�����Ʊ��ѡ��
����s[0]�У��ڶ�������s[1]�С�����
�������һ�������뼴��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn];

struct pp{
    int v,id;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v)
        return x.id<y.id;
    return x.v>y.v;
}

int main()
{
    int i,j,n,m,tot;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++){
            for(j=i;j<n+i;j++){
                scanf("%d",&s[j].v);
                s[j].id=j-i;
            }
            sort(s+i,s+n+i,cmp);
            a[s[i].id]++;
        }
        int res=-1;
        for(i=0;i<n;i++)
            if(res==-1 || a[res]<a[i])
                res=i;
        printf("%d\n",res+1);
    }
    return 0;
}
