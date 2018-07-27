/*
��������
���ȼ����n���ˣ���r���������ĸ��ʣ���Ϊtot��
��ô�ڴ������£���i���������ĸ��ʾ�����������
�ҵ��ڣ�n������r������������r�������е�i���˵�
������Ϊchoose[i],��ô������������µ�i��������
�ĸ��ʾ���choose[i]/tot

P(A|B)=P(AB)/P(B)
choose[i] -_> P(AB)
tot       -_> P(B)

���Ա���ʱҪ����choose����
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=22;
double p[maxn],choose[maxn],tot;

int main()
{
    int i,j,n,r,kcase=1;
    while(scanf("%d%d",&n,&r)){
        if(n==0 && r==0) break;
        for(i=0;i<n;i++)
            scanf("%lf",&p[i]);
        tot=0;
        memset(choose,0,sizeof(choose));
        for(i=0;i<(1<<n);i++){      //ö��
            int num=0;
            for(j=i;j!=0;j>>=1) num+=j&1;
            if(num!=r) continue;            //Ҫ��ǡ����r�����������
            double t=1;
            for(j=0;j<n;j++){
                if((i>>j)&1)
                    t*=p[j];        //��j�������ˣ����ʾ���p[i]��û�����1-p[i]
                else t*=(1-p[j]);
            }
            for(j=0;j<n;j++)
                if((i>>j)&1)
                    choose[j]+=t;    //ÿ��Ҫ��������ʼӵ���j���������ĸ�����
            tot+=t;
        }
        printf("Case %d:\n",kcase++);
        for(i=0;i<n;++i)
            printf("%.6f\n",choose[i]/tot);
    }
    return 0;
}
