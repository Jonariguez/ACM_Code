/*
�������������ص���Կ��ĳ������׽����Ǹ�
�����ǵ����ģ���������Ҫ��1��ʼһ��һ��
������(��֤������ǵ�����)
�� 1->2   12->3  123->4  1234->5 ....
ֻҪ1�ӿ�ͷһֱ�����Ĳ��öϿ��������Ķ�Ҫ
�Ͽ��������ģ�Ȼ��������
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn];

int main()
{
    int i,j,k,n,m,res;
    while(scanf("%d%d",&n,&k)!=EOF){
        res=0;
        int x;
        for(i=0;i<k;i++){
            scanf("%d",&m);
            for(j=0;j<m;j++) scanf("%d",&a[j]);
            if(a[0]!=1){
                res+=m-1;continue;
            }
            for(j=0;j<m;j++)
                if(a[j]!=j+1) break;
            res+=m-j;
        }
        printf("%d\n",res*2+k-1);
    }
    return 0;
}
