/*
������˼��
Ԥ�������ÿ������ʼ����s�����Ƿ���1-s��һ��ȫ����
����ǣ�����������±�ok����Ϊture������Ϊfalse��
Ȼ��ö��[0,s-1]λ�ã�����Ƿ�ϸ񣬼��ķ����ǣ�
���i��i+s,i+2*s,i+3*s,...���������Щ�±���ڵ�ok
ȫ��true����ô��i����ʼ��һ�����ܣ���+1��
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
//ע������Ĵ�С
int a[maxn*3],cnt[maxn];
bool ok[maxn*2];

int main()
{
    int i,j,s,res,n,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&s,&n);
        memset(ok,false,sizeof(ok));
        memset(cnt,0,sizeof(cnt));
        fill(a,a+n+2*s+1,-1);
        int sum=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i+s]);
        for(i=0;i<n+s+1;i++){
            if(sum==s) ok[i]=1;
            if(i<s && sum==i) ok[i]=1;      //����ǰ���
            if(i>n && sum==n-i+s) ok[i]=1;  //��������

            if(a[i]!=-1 && cnt[a[i]]--==1) sum--;
            if(a[i+s]!=-1 && cnt[a[i+s]]++==0) sum++;
        }
        int res=0;
        for(i=0;i<s;i++){
            int yes=1;
            for(j=i;j<n+s+1;j+=s)
                if(!ok[j]){ yes=0;break;}
            if(yes) res++;
        }
        if(res==n+1)        //,,,���Ǹ�����
            res=s;
        printf("%d\n",res);
    }
    return 0;
}

/*
������Ҫע��ģ������ӣ�
s=4,  ����a: 3 4 [1 2 3 4] [3 2 1 4] 3 2  (�±�����0)
�������м���Ƿ��ϴ��ڵģ���ok[2]=ok[6]=true,���ǻ�Ҫ
����ǰ���3 4��������3 4��û���ظ����ֵģ�����������
ǰ���������ռ䣬��ô��Ӧ����a[-2]=x,a[-1]=y,a[0]=3,a[1]=4.
��Ϊ3 4���ظ����������Ǿ�ȡx��y�ֱ�Ϊ1,2������3 4Ҳ
һ��������(��ʵ���ǿ�ͷ����s����ֻҪû���ظ����ֵ�
�����������ճ�һ������),��ok[-2]=true��
��Ϊ�����±��޸�������������Ҫ����������ǰ��Ԥ����
s���ռ䣬����ʼ��Ϊ-1����ʾ�����֡�(if(i<s && ..))
�����3 2Ҳ���ƴ���(if(i>n && ..))
�����£�
�±�:-3 -2 -1 0 1 2  3 4 5 6  7 8 9 10 11 12
����: x  x  x 3 4 4 [1 2 3 4][3 2 1 4] 3  2
ok[-3]=ok[-2]=true,��Ϊa[1],a[2]����4����ôok[-1]=false
ͬ��ok[0],ok[1]����false.
*/
