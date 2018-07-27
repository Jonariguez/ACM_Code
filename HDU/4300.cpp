/*
��һ�еķ�������table��ڶ��е��Ĵ�
����str�(�Ĵ�=����+����)
����֪�����Ĵ������һ���������ģ����Ŀ��ܲ�����
Ҳ����û�У�������û���ص����������ĵĳ��Ȳ��ᳬ��
�Ĵ���һ�룬ͬ�������Ĳ��������Ĵ���һ�롣
�ʹ��⣬���ǵ�Ŀ���ǣ������ķ�������ĺ�ʹǰ���������
����ɵ����ĺͺ���ԭ��������ƥ��ľ����ࡣ
�����ǽ����ķ��������ʱ����ȫ�������룬��Ϊȫ������
��������ľͱ��ƻ�����ʧ����Ϊ���ĵĳ������ƣ����Ǿ;�����
�ı������ģ�����
���Ĵ���ǰһ�뵱�����Ĳ���������ģ���һ�뱣���������ģ�
Ȼ��ȥKMPƥ�䣬��¼ƥ������ĸ�����
ƥ���ϵľ������ĺ����ĵĶ�Ӧ��ûƥ���ϵ�ֻ�ܵ�����Ŀ
�����˹�û��������ȫ����Ȼ��table����ûƥ���ϵ����ķ���
һ�¾����ˡ�

k=Next[i]�ĺ����ǣ���i��ʧ��(T[j]!=P[i])��i����ǰ����ʲôλ�ã����
һֱk=next[k]����ǰ�����Ļ������������һ�£��������ʱ����T�̶�����
�Ļ�����k���ϼ�С����ôģʽ���ͻ᲻�ϵı�����������������ģʽ���ص�
�ĳ���(ָ�ĵ���ʧ��λ��֮ǰ�ص��ĳ���)ҲԽ��Խ�̡�

��������������ͣ������ǰ�str��ǰ�벿�ַ��룬��������str����next��
��ô������Ҫǰ�벿�ֺͺ�벿�ֵ��ص����ȣ���Ҫ�̶�һ����Ȼ����k=Next[len]��
Ȼ������һֱ�������ģʽ��"�������ߵ��ص�����С��һ��"�����ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char table[30],str[maxn],rstr[maxn],mstr[maxn];
int vis[30],mp[30];
int Next[maxn];

void get_next(char *s){
    int i,j,n;
    n=strlen(s);
    Next[0]=Next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && s[j]!=s[i])
            j=Next[j];
        if(s[j]==s[i]) j++;
        Next[i+1]=j;
    }
}

int main()
{
    int i,j,T,n,len;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",table,str);
        for(i=0;i<26;i++)
            mp[table[i]-'a']=i;
        len=strlen(str);
        strcpy(mstr,str);
        for(i=0;i<len/2;i++)        //mstrֻҪ��ǰһ���ӳ��
            mstr[i]='a'+mp[str[i]-'a'];
   /*     for(i=(len+1)/2;i<len;i++)  //rstrֻҪstr�ĺ�һ��
            rstr[i-(len+1)/2]=str[i];
        rstr[i-(len+1)/2]='\0';           //��mstr��rstrƥ�䣬mstr��ģʽ��
        n=strlen(mstr);   */
        get_next(mstr);
    /*    for(i=0;i<=n;i++) printf("%d ",Next[i]);
        printf("\n");
        printf("rstr=%s\nmstr=%s\n",rstr,mstr);
        printf("k=%d\n",k);*/
        int k=Next[len];
        while(k>len/2)
            k=Next[k];
        printf("%s",str);
        for(i=k;i<len-k;i++)
            printf("%c",'a'+mp[str[i]-'a']);
        printf("\n");
    }
    return 0;
}
