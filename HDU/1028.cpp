/****************
*ID:hdu1028
*Auth:Jonariguez
*****************
ĸ����
(1+x+x^2+x^3..)*(1+x^2+x^4+...)*..*(1+x^n+x^(2n)+..)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=120+10;

int a[maxn],b[maxn];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<=n;i++)
            a[i]=1;
        for(i=2;i<=n;i++){      //i�Ǹü���ڼ������������
            for(j=0;j<=n;j++)       //j��Ӧָ����ϵ������j����ǰx^j��ϵ��
                for(k=0;k+j<=n;k+=i)        //��i��������x��ָ�����Ϊi������k���α�ʾ��i����������x��ϵ��
                    b[k+j]+=a[j];
                memcpy(a,b,sizeof(b));
                memset(b,0,sizeof(b));
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
