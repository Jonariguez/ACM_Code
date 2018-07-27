/*
C(n,k)=C(n,k-1)*(n-k+1)/k
������Ҫ��ȫ�����������ָ������������
���ǿ���ö��m�������ӣ�Ȼ�����ÿ��������
���ȫ����C����������Ӷ�����
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
vector<int> fac,cnt,res;
int mark[maxn];

void cal(int m){
    int i,n;
    n=floor(sqrt(m) + 0.5);
    for(i=2;i<=n;i++){
        if(m%i==0){
            fac.push_back(i);
            int c=0;
            while(m%i==0){
                c++;
                m/=i;
            }
            cnt.push_back(c);
        }
    }
    if(m>1){
        fac.push_back(m);
        cnt.push_back(1);
    }
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        fac.clear();cnt.clear();
        cal(m);
        n--;
        memset(mark,0,sizeof(mark));
        for(i=0;i<fac.size();i++){
            int p=fac[i],c=0,x;
            x=m;
            for(int k=1;k<n;k++){
                x=n-k+1;
                while(x%p==0) {x/=p;c++;}
                x=k;
                while(x%p==0) {x/=p;c--;}
                if(c<cnt[i]) mark[k]=1;
            }
        }
        res.clear();
        for(i=1;i<n;i++)
            if(!mark[i]) res.push_back(i+1);
        printf("%d\n",res.size());
        if(!res.empty())
            for(i=0;i<res.size();i++)
                printf("%d%c",res[i],i==res.size()-1?'\n':' ');
        else printf("\n");              //�������������ݣ�û���ݴ�ӡ�����У����ꡣ������
    }
    return 0;
}

