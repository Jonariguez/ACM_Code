/****************
*PID:cdvs1098
*Auth:Jonariguez
*****************
̰��
��Ϊ�ƶ������ǻ�״�ģ����Դ�������ɨһ��ͺ���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100+10;
int a[maxn];

int main()
{
    int i,j,n,res,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int A=sum/n;
    res=0;
    for(i=0;i<n-1;i++){
        if(a[i]==A) continue;
        res++;
        a[i+1]+=a[i]-A;
    }
    printf("%d\n",res);
    return 0;
}
