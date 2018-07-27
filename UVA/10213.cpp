/*
欧拉公式：V-E+F=2
V顶点，E边，F面
枚举顶点向其他顶点连线得到一条对角线，
该对角线左边有i个点，右边有n-i-2个点，
这些点连线在该对角线上共有i*(n-i-2)个
交点，划分成i*(n-i-2)+1条线段。
这样的话，点重复计算4次，边重复算2次
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
