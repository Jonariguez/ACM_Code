/****************
*PID:uva1620
*Auth:Jonariguez
*****************
a1 a2 a3...an
һ�����У��ѵ�һ�����ŵ������ȥ�����������
�ı仯�ǣ�x+n-1-2*i������x��ԭ�������������i��a1�Ĵ�С����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int a[maxn];

int main()
{
    int i,j,cnt,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(j=1;j<i;j++)
                if(a[j]>a[i]) cnt++;
        }
        if(n&1 && cnt&1)
            printf("impossible\n");
        else printf("possible\n");
    }
    return 0;
}
