/*
ŷ����ʽ��V-E+F=2
V���㣬E�ߣ�F��
ö�ٶ����������������ߵõ�һ���Խ��ߣ�
�öԽ��������i���㣬�ұ���n-i-2���㣬
��Щ�������ڸöԽ����Ϲ���i*(n-i-2)��
���㣬���ֳ�i*(n-i-2)+1���߶Ρ�
�����Ļ������ظ�����4�Σ����ظ���2��
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    ll i,n;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        ll v=0,e=0;
        for(i=0;i<=n-2;i++){
            v+=i*(n-i-2);
            e+=i*(n-i-2)+1;
        }
        v*=n;v/=4;e*=n;e/=2;
        v+=n;e+=n;
        printf("%lld\n",e-v+1);
    }
    return 0;
}
