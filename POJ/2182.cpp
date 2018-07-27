/*
BIT+����(������һ���ö��֣��������)
*/
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

const int maxn=8000+10;

int bit[maxn],p[maxn],n;

void add(int i,int v){
    while(i<=n){
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

bool C(int x,int small){
    return (sum(x-1)+small+1)>=x;
}


int ans[maxn];
set<int> s;         //�����õ����ʣ���Ǹ���������һ�ַ�������1-n�ĺ�(n*(n-1)/2)��ȥ�Ѿ�ȷ���˵����ĺ�sum����ʣ����

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        s.insert(i);
    for(i=1;i<n;i++)
        scanf("%d",&p[i]);
    for(i=n-1;i>0;i--){
        int l=1,r=n,t=p[i];
        while(r-l>0){           //���ö��ֲ���һ��ֵ��ʹ�����������Ѿ������ֵ�б��Լ�С�ĸ���+���Լ�ǰ���ֱ��Լ�С��
            int m=(l+r)/2+1;    //���ĸ���+1=������ô���������Ҫ�����λ�ò������
            if(C(m,t))          //��Ϊ�����ÿ�ζ�Ψһ�������ö��ֶ�ֵ�����������Ͻ���½磬ע��һ�¡�
                l=m;
            else r=m-1;
        }
        s.erase(l);         //���������֮���������ɾ��
        ans[i]=l;
        add(l,1);
    }
    set<int>::iterator it;
    it=s.begin();           //���ʣ��һ�����϶���ǰ��û�����ˣ�Ҳ���������ǵ�һ����
    ans[0]=*it;
    for(i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}

