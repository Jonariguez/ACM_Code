/*http://www.cnblogs.com/dolphin0520/archive/2011/10/15/2213752.html
����ǰ׺�����е����ʣ�
���ã��������ɸ��ַ������У���������
�ַ�������X[1....n]��Y[1....m]�����X��Y��ǰ׺��
���ڶ����е��ַ������а��ֵ�˳�������
X[1..n]��Y[1....m]��λ���ϱ�Ȼ��ֱ�����ڻ���
������ڵġ��������ָ�����ַ�������Z[1....t]��
ʹ��X��Z��ǰ׺(X��Zֱ������)��Z��Y��ǰ׺(Z��Y
ֱ������)����X��YҲ����Ϊ�����ڵġ�
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=500000+10;

struct Str{
    int len;
    char ss[11];
}s[10005];

int cmp(const Str &x,const Str &y){
    return strcmp(x.ss,y.ss)<0;
}

int Strcmp(char *a,char *b){    //�鿴a�Ƿ���b��ǰ׺������Ƿ���0
    int i,n=strlen(a);
    for(i=0;i<n;i++)
        if(a[i]!=b[i]) return 1;
    return 0;
}

int main()
{
    int i,n,t;
    char str[11];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",s[i].ss);
            s[i].len=strlen(s[i].ss);
        }
        sort(s,s+n,cmp);
        for(i=0;i<n-1;i++){
            int len1=s[i].len,len2=s[i+1].len;
            if(len1<=len2 && Strcmp(s[i].ss,s[i+1].ss)==0)
                break;
        }
        if(i==n-1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
