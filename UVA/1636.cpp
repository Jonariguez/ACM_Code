/*
ֱ��SHOOT���������ʣ���Ϊ��֮ǰ��һ����ǹ��
�����SHOOT�Ļ������뱣֤��һǹҲ�ǿ�ǹ����
����0����00(�������ʣ��ڵ�һǹ�ǿյ�����£�
�ڶ�ǹҲ��)
��ROTATE���Ǽ򵥸��ʣ���0���ֵĸ���

�����ó˷����ó�������
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
const int maxn=220;
char str[maxn];

int main()
{
    int i,a,b,n;
    while(scanf("%s",str)!=EOF){
        n=strlen(str);
        a=b=0;
        for(i=0;i<n-1;i++){
            if(str[i]=='0' && str[i+1]=='0') a++;
            if(str[i]=='0') b++;
        }
        if(str[0]=='0' && str[n-1]=='0') a++;
        if(str[n-1]=='0') b++;
        if(b*b==a*n)
            printf("EQUAL\n");
        else if(a*n>b*b)
            printf("SHOOT\n");
        else printf("ROTATE\n");
    }
    return 0;
}
