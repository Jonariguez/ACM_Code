/*
aͷţ��b��������c����
һ��a+b����
�����������
��ѡ�е�����ţ��a/(a+b)
�ĳɳ��� b/(a+b-c-1)
��ѡ�е����ǳ���b/(a+b)
�ĳɳ��� (b-1)/(a+b-c-1)
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

int main()
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
        printf("%.5f\n",(a/(a+b)*b/(a+b-c-1)+b/(a+b)*(b-1)/(a+b-c-1)));
    return 0;
}
