/*
�������ҹ��ɣ��������򿪵�һ���⡣
����ڵ���12����ô�𰸾���9(=12-2^2+1)��15(=12+2^2-1)����2�ǲ���-1
����8������1(=8-2^3+1)��15(=8+2^3-1)������3�ǲ���-1
��������ֻҪ֪���ڵ�x���ڵĲ����Ϳ���ֱ�ӳ��⡣
���ڵ�x���ڵĲ����и����ɣ��������deep,��ô��x%(2^deep)==2^(deep-1)��
����ö�ٲ������ɡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main()
{
    int T;
    ll n,deep;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        for(deep=1;deep<=31;deep++)
            if(n%(1<<deep)==(1<<(deep-1)))
                break;
        printf("%lld %lld\n",n-(1<<(deep-1))+1,n+(1<<(deep-1))-1);
    }
    return 0;
}
