/*
���˰�26����ĸÿ��ѡһ��
������ǰ�����γ�26����ͬ�ģ�
��ô�Ժ��ں����λ�÷ŵ�ʱ��
���ܺ�ǰһ��λ����ͬ��ÿ��λ��
��25�����
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int i,n;
    char s[22];
    while(scanf("%s",s)!=EOF){
        n=strlen(s);
        printf("%d\n",n*25+26);
    }
    return 0;
}
