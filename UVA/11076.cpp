/****************
*PID:uva11076
*Auth:Jonariguez
*****************
����ͳ������1���ֵĴ��� ����0��9ÿ�����γ���ni��
������1�ڹ̶�һλ�ϳ����ֵĴ���Ϊ n��/(n0!*(n1-1)!*....*n9!)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

int cnt[15],a[15];
ULL fact[15];

int main()
{
    int i,j,n;
    fact[0]=1;
    for(i=1;i<=12;i++)
        fact[i]=fact[i-1]*i;
    while(scanf("%d",&n),n){
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        if(cnt[0]==n){
            printf("0\n");continue;
        }
        ULL sum=0,res=0,temp=1;
        for(i=0;i<10;i++){
            int x=i;
            if(cnt[x]==0) continue;
            ULL temp=fact[cnt[x]-1];
            for(j=0;j<10;j++){
                if(j==i) continue;
                temp*=fact[cnt[j]];
            }
            temp=fact[n-1]/temp*i;      //����Ҫ����i
            sum+=temp;
        }
        for(i=0;i<n;i++){
            res+=sum;
            sum*=10;
        }
        printf("%llu\n",res);
    }
    return 0;
}

