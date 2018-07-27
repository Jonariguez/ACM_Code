/****************
*PID:573Adiv1
*Auth:Jonariguez
*****************
��������ǵ���С������lcm��Ȼ��鿴���Ǵӱ���
�䵽lcm�Ƿ�ֻ��Ҫ*2��*3������t=lcm/a[i],��ô
t��������Ӧ��û�г���2��3֮���������
������ʵ�ᳬʱ��
���ǿ������´���ÿ������һֱ����2,3����ô���ʣ�µ�
����ȾͿ��ԣ���һ���򲻿���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long Int;

const int maxn=100000+10;
int a[maxn];

int cal(int n){
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    return n;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]=cal(a[i]);
        }
        bool yes=true;
        for(i=1;i<n;i++){
            if(a[i]!=a[0]){
                yes=false;break;
            }
        }
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
