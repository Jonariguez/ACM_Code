/****************
*PID:la3708
*Auth:Jonariguez
*****************
���õȱ����ţ�������Բ���ų�һ���ܳ�Ϊn+m��Բ��
����ԭ�еĵ�i�����ܵ�λ�ÿ������ù�ʽ�ó���i/n*(n+m)
����Ϊ��Բ�Ѿ����ų��ܳ�Ϊn+m,���������m������֮��
ÿһ�����ܶ����������ϣ�������n������һ�����������ϣ�
���Դ�ʱ��n�������в����������ϵ��������������������
�ƶ��������ƶ��������ŵ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double pos,res=0.0;
        for(i=1;i<n;i++){
            pos=(double)i/n*(n+m);
            res+=fabs(pos-floor(pos+0.5))/(n+m);      //floor()������������,�����˳���(n+m),����ת���ɳ���Ϊ1��Բ
        }
        printf("%.4lf\n",res*10000);
    }
    return 0;
}
