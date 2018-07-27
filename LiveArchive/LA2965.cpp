/****************
*PID:la2965
*Auth:Jonariguez
*****************
��ÿ���ַ�����A-Z��26����ĸ���ֵĴ�������ż�ԣ���
����ַ�ѹ����һ��26Ϊ��������Ȼ�������ѡȡ������
���ֵ����0.
n=24̫����;��������
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=26;
int a[maxn];
char str[1000];
//table[x]��ʾǰn1����^�Ƿ���x��cnt[x]:���ֵΪx�ģ�ѡ��������������ans[x]�������Ʊ���ѡ���ļ�������
map<int,int> table,cnt,ans;

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%s",str+1);
            a[i]=0;
            for(j=1;str[j]!='\0';j++)
                a[i]^=(1<<(str[j]-'A'));
        }
        table.clear();cnt.clear();ans.clear();
        int n1=n/2,mask;
        for(mask=0;mask<(1<<n1);mask++){
            int x=0,c=0;
            for(j=0;j<n1;j++)
                if((mask>>j)&1){
                    x^=a[j];c++;
                }
            if(!table.count(x)){
                table[x]=1;cnt[x]=c;ans[x]=mask;
            }else {
                if(c>cnt[x]){
                    table[x]=1;cnt[x]=c;ans[x]=mask;
                }
            }
        }
        int n2=n-n1,res=0,now=0;
        for(mask=0;mask<(1<<n2);mask++){
            int x=0,c=0;
            for(j=0;j<n2;j++){
                if((mask>>j)&1){
                    x^=a[j+n1];c++;
                }
            }
            if(table[x]){
                if(now<cnt[x]+c){
                    now=cnt[x]+c;res=((mask<<n1)|ans[x]);
                }
            }else {
                if(x==0 && now<c){
                    now=c;res=mask;
                }
            }
        }
        printf("%d\n",now);
        for(i=0;i<n;i++){
            if((res>>i)&1) printf("%d ",i+1);
        }
        puts("");
    }
    return 0;
}
