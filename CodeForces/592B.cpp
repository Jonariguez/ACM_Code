/****************
*PID:592b div2
*Auth:Jonariguez
*****************
���ڵ�ǰ����i����Ϊ��<i������>i����
�ֱ�Ϊi-3��n-i-1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    LL i,j,n,res;
    while(scanf("%I64d",&n)!=EOF){
        res=n-2;
        for(i=2;i<=n;i++){
            res+=max(0LL,i-3);
            res+=max(0LL,n-1-i);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
