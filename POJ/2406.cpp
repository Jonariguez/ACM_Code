/*
Ҳ����˵������ĳ���ַ���S������ΪN���ɳ���Ϊn��
�ַ���s�ظ�R�εõ�����R��2ʱ��Ȼ��S[1..N-n]=S[n+1..N]��
��ô����KMP�㷨��˵������fail[N]=N-n����ʱn�϶��Ѿ�
����С���ˡ�
Ȼ��ֻ��Ҫ�ж�N�Ƿ�n�ı������������N/n���ɡ��������1��
*/
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
char str[maxn];
int next[maxn];

void get_next(){
    int i,j,n;
    n=strlen(str);
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && str[j]!=str[i])
            j=next[j];
        if(str[j]==str[i]) j++;
        next[i+1]=j;
    }
}

int main()
{
    int i,j,n;
    while(scanf("%s",str)){
        if(str[0]=='.') break;
        get_next();
        n=strlen(str);
        if(n%(n-next[n])==0)
            printf("%d\n",n/(n-next[n]));
        else printf("1\n");
    }
    return 0;
}
