/****************
*PID:la3882
*Auth:Jonariguez
*****************
Լɪ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&k,&m)){
        if(n==0 && m==0 && k==0) break;
        int f=0;            //��Ϊһ��ʼ��ɱ����һ��m��Ȼ����n-1����Լɪ����������ֻ����n-1�Ľ��f
        for(i=2;i<n;i++)
            f=(f+k)%i;      //n-1���˵�ʱ��������f��
        f=(f+m)%n;          //n->n-1ʱ������m�����������Ҫ+m���ƻ�ȥ�������+1��ʾ��Ŀ���±��1��ʼ
        printf("%d\n",f+1);
    }
    return 0;
}
