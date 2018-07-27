/*
BIT(���⣡!)
�����н����������·�������˵��ţ�ĳ��·����һ��·�ȣ���һ�����С��������һ��
��Ŵ���a--b��c--d����a>c,b<d��a<c,b>d��
��BIT���������ߴ���(������BIT������������߻�������),������Ȼ��֤һ��С��
��ȥ������һ����ű��Լ�С�ĸ������ۼӼ���
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000+10;

int bit[maxn],n,m;
struct pp{
    int x,y;
}s[1000000];

void add(int i,int v){
    while(i<=m){
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

int cmp(const pp &a,const pp &b){
    if(a.x==b.x)
        return a.y>b.y;     //������y����������Բ��ô���x��ȵ����
    return a.x>b.x;
}

int main()
{
    int i,j,k,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        memset(bit,0,sizeof(bit));
        for(i=0;i<k;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        sort(s,s+k,cmp);
        ll res=0;
        add(s[0].y,1);
        for(i=1;i<k;i++){
            res+=sum(s[i].y-1);
            add(s[i].y,1);
        }
        printf("Test case %d: %lld\n",kcase++,res);
    }
    return 0;
}
