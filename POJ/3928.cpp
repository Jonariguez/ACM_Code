/*
BIT(��������)

�����i���������У���������(����ӷ�)��ǰС���ǰ���С
�����A1��Ai-1�б�AiС����x1������ô��Ai��ľ���y1=(i-1-x1)����
�����Ai+1��An�б�AiС����x2������ô��Ai��ľ���y2=(n-i-x2)��
�ֲ��˷��������е�x1*y2+x2*y1���Ǵ𰸡�
����Ŷ��x1��x2��������״����(��AiС��������Aiǰ����)��̬ά�����(����)��
Ȼ��y1��y2�����������
��x2ʱ����˵�������Լ�����ı��Լ�С�ĸ�������ô���ǿ���������벢��ѯ
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=20000+10;
const int N=100000;

int bit1[N+10],bit2[N+10];
int a[maxn],small_front[maxn],small_behind[maxn];

void add(int *bit,int i,int v){
    while(i<=N){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int *bit,int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll res;
        for(i=1;i<=n;i++){
            small_front[i]=sum(bit1,a[i]);  //���������a[i]
            add(bit1,a[i],1);
        }
        for(i=n;i>=1;i--){
            small_behind[i]=sum(bit2,a[i]); //���������a[i],����i
            add(bit2,a[i],1);
        }
        res=0;
        for(i=1;i<=n;i++){
            res+=small_front[i]*(n-i-small_behind[i]);
            res+=(i-1-small_front[i])*small_behind[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}
