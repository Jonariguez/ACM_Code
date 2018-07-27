/*
hash
�����ԣ���ǰ��Ĵ���vis�������[1,nc],
����Ҫ����nc���Ƶ�������[0,nc-1],�����
ʱ�����Ǿͼ�1��vis[str[j]]-1
����Ҳ��~
*/
#include <stdio.h>
#include <string.h>

const int maxn=16000000+10;
char str[maxn];
bool hash[maxn];
int vis[10000];

int main()
{
    int i,j,n,nc,len;
    scanf("%d%d%s",&n,&nc,str);
    int cnt=0;
    len=strlen(str);
    for(i=0;i<len;i++){
        if(vis[str[i]]==0)
            vis[str[i]]=++cnt;
        if(cnt==nc) break;      //��Ϊһ�����ֻ��nc���ַ�������Ѿ�Ϊnc���ַ�
    }                           //�����(��vis��)����ô�Ժ�Ϳ϶�û�����ַ�������
    int sum=0,res=0;
    for(i=0;i+n-1<len;i++){
        sum=0;
        for(j=i;j<i+n;j++)              //vis��Ҳ���൱�ڰ�ÿ���ַ�ת��Ϊnc����������Ȼ��
            sum=sum*nc+vis[str[j]]-1;     //n���ȵ��Ӵ�ת��Ϊһ��nc���Ƶ�������hash
        if(hash[sum]==0){
            res++;hash[sum]=1;
        }
    }
    printf("%d\n",res);
    return 0;
}
