/****************
*PID:hdu5587
*Auth:Jonariguez
*****************
sum=1��cnt=1���ֱ�����ʼʱ���е��ܺͺ�Ԫ�ظ�����
ÿ����һ��sum�ı仯��sum=sum*2+cnt+1;
cnt�ı仯:cnt=cnt*2+1
һֱ������ڵ���m����Ȼ��һ��һ���˻�����
cnt--;cnt/=2;
sum-=cnt+1;sum/=2;
��Ϊÿ�λ���0����һ�Σ�m--��
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
    LL i,j,n,m;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&m);
        LL now=1,cnt=1,sum=1,res=0;
        while(true){
           // res+=sum;
            if(cnt*2+1>=m) break;
            sum=(sum*2+cnt+1);
            cnt=(cnt*2+1);
        }
        res+=sum;
        m-=cnt;
        res+=m;
        m--;
        while(m>0){
            if(m>(cnt/2)){
                res+=(m-cnt/2);
                cnt--;cnt/=2;sum-=(cnt+1);
                sum/=2;
                res+=sum;
                m-=cnt;m--;
            }else {
                cnt--;cnt/=2;sum-=(cnt+1);sum/=2;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}

