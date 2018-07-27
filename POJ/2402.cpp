/****************
*PID:poj2402
*Auth:Jonariguez
*****************
����Ϊk���������γɵĻ������ĸ���Ϊ��9*10^((k-1)/2)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[22],cnt[22];
int vis[10];

int main()
{
    LL i,j,n;
    fact[0]=1;
    for(i=1;i<=20;i++)          //fact[]��cnt[]�㵽20,15��WA
        fact[i]=fact[i-1]*10;
    cnt[1]=9;
    for(i=2;i<=20;i++)
        cnt[i]=9*fact[(i-1)/2];
    while(scanf("%lld",&n),n){
        LL k=n,p;
        for(p=1;p<=20;p++)
            if(k<=cnt[p]) break;
            else k-=cnt[p];
      //  printf("%I64d\n",p);
        memset(vis,0,sizeof(vis));      //������vis���أ���Ϊ����������ǿ������ظ��ġ�������������1~n��һ������
        LL now=0,res=0,m=(p+1)/2;         //p��ʾ��n���������Ǽ�λ����m��ʾ�м�λ�ã�������p����ż��̸��
        for(i=1;i<=m;i++){          //��1��mλ����ȷ�����֣�����İ����Ĺ���ȫ
            LL cnt=0;
            for(j=0;j<10;j++){
                if(j==0 && i==1) continue;
                if(now+fact[m-i]>=k) break;
                now+=fact[m-i];
            }
         //   printf("j=%I64d\n",j);
          //  vis[j]=1;
            res=res*10+j;
        }
        k=res;
        if(p&1) k/=10;  //���������Ϊ�����м�һλ��Ҫ�����м�һλ��ǰһλ����һλ���𰸵ĺ��油�ɻ���
        while(k){
            res=res*10+k%10;
            k/=10;
        }
        printf("%lld\n",res);   //I64d��WA��������
    }
    return 0;
}
