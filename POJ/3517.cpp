/****************
*PID:poj3517
*Auth:Jonariguez
*****************
Լɪ�����ʽ��f[n]=(f[n-1]+m)%n
���֮����+1����ת���ɱ�Ŵ�1��ʼ����ʽ�Ǵ�0��ʼ��)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,n,m,k,f;
    while(scanf("%d%d%d",&n,&k,&m)){
        if(n==0 && k==0 && m==0) break;
        f=0;
        for(i=2;i<n;i++)
            f=(f+k)%i;
        f=(f+m)%n;
        printf("%d\n",f+1);
    }
    return 0;
}
