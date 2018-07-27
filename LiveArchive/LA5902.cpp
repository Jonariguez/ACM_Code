/*
BIT
��Ϊÿ�ζ�Ҫ��ǰ�������Ծ�Ҫǰ��Ԥ����100000(q,��ѯ�Ĵ�������)��λ�ã�
����BIT������[100001,200000]�ϣ�ѯ�ʵ�һ��x1,��x1λ��-1��0��Ȼ�����100000����
add(100000,1)��ѯ�ʵڶ���x2,ͬ����x2����0������99999����add(99999,1)����
��mpӳ��ÿ�����̵�λ��
*/
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

const int maxn=100000+10;
int bit[maxn*2],n,ans[maxn],mp[maxn];

void add(int i,int v){
    while(i<=200000){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,T,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        memset(bit,0,sizeof(bit));
        for(i=1;i<=n;i++){
            add(i+100000,1);
            mp[i]=i+100000;
        }
        int x,tot=0,index=100000;
        while(q--){
            scanf("%d",&x);
            int t=mp[x];
            printf("%d",sum(t-1));
            add(t,-1);
            mp[x]=index--;
            add(mp[x],1);
            if(q)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
