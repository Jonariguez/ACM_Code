/*
������ô򿪵�1�����ӿ��ˣ�����2�����ӻ���i�š�
��֮ǰ�򿪹�n+(n-i)�κ��ӣ�n���Ǻ���1��n-i����
����2����ô���ʾ���C(2*n-i,n)*p^(n+1)*(1-p)^(n-i)��
p��ָ����n+1����Ϊ���Ҫ��һ��1

C̫�󣬺������̫С����ʧ����̫�࣬���ö�������

��v1[i]=ln(C(2*n-i,n)) + (n+1)*ln(p) + (n-i)*ln(1-p);
�����򿪵�1�����ӿգ���2����ʣi������Ӧ�ĸ��ʾ���exp(v1[i])

һ��ʼ�����ż���ln(C(2*n-i,n))��Ҫ���±������㣬�����Ļ�
����O(n^2)�ˣ��϶����У������뵽�ˣ�
C(2*n-i,n)=(2*n-i)!/(n!*(n-i)!),��v1[i]ȡ����֮����ǣ�
    ��        ��          ��              ��            ��
ln(2*n-i)! - ln(n!) - ln((n-i)!) + (n+1)*ln(p) + (n-i)*ln(1-p)

��i�任ʱֻҪ�٣��ۣ��ݱ任������i����1
��  Ӧ�ü�Сln(2*n-i+1)
��  Ӧ������ln(n-i+1)
��  Ӧ�ü���ln(1-p)

������ln(C(2*n-i,n))��ֻ��Ҫһ��ʼ����������(LNC)��
֮��ֻ��O(1)��ʱ�����õ������ڵ�v1[i+1]....
(Ҳ����Ԥ�����log(1),log(2)��ǰ׺�ͣ�����O(1)����)

ͬ�����ں���2Ҳһ����
v2[i]=ln(C(2*n-i,n)) + (n+1)*ln(1-p) + (n-i)*ln(p);

Ҫ��long double
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=200000+5;
long double v1[maxn],v2[maxn];

int main()
{
    int i,j,n,kcase=1;
    double p;
    long double LNC;
    while(scanf("%d%lf",&n,&p)!=EOF){
        LNC=0;
        for(i=1;i<=n;i++){
            LNC+=log(i+n);
            LNC-=log(i);
        }
        v1[0]=LNC+(n+1)*log(p)+n*log(1-p);
        v2[0]=LNC+(n+1)*log(1-p)+n*log(p);
        for(i=1;i<=n;i++){
            long double exc=log(n-i+1)-log(2*n-i+1);     //ע������Ķ�Ҫ+1����Ϊi�������һ�δ���1
            v1[i]=v1[i-1]+exc-log(1-p);
            v2[i]=v2[i-1]+exc-log(p);
        }
        double res=0;
        for(i=1;i<=n;i++)
            res+=i*(exp(v1[i])+exp(v2[i]));
        printf("Case %d: %.6lf\n",kcase++,res);
    }
    return 0;
}

