/****************
*PID:hdu5623
*Auth:Jonariguez
*****************
dp[i]��ʾ��ǰi������������Ӯ����������
ת�ƣ�dp[i]=max{a[j+1]-dp[j]}(1<=j<i)
Ϊʲô�Ǽ��أ�ת�Ʊ�ʾ����������ȡa[j+1..i]��Щ����
ȡ��֮��ʣj������ͬʱ�Է���������֣���ô�Է���
�÷־���dp[j]���������ĵ÷���a[j+1]������a[j+1]-dp[j]
���Ǳ����÷֣�Ȼ��ȡ�����ֵ���ɡ�
��nowά�����ֵ��ֻҪÿȷ��һ��״̬dp[i]����ô����
a[i+1]-dp[i]������now���ɡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=50000+10;
LL dp[maxn],a[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        dp[0]=0;
        LL now=0;
        for(i=1;i<=n;i++){
            now=max(now,a[i]-dp[i-1]);
            dp[i]=now;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
