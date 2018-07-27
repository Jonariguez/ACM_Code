/****************
*PID:hdu5583
*Auth:Jonariguez
*****************
����ɢ���������������ȫ������ɫ��һ�����øı�������š�
��ɢ��֮��Ȼ��ö��ÿ����ɢ�飬�ı�ÿ�����ܵ���ɫ���������ֵ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
char s[maxn];
LL a[maxn];

int main()
{
    LL i,j,n,m,T,kcase=1;
    scanf("%I64d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        LL cnt=0;
        LL res=0;
        for(i=1;i<=n;){ //��ɢ��
            j=i;
            while(j<=n && s[j]==s[i]) j++;
            a[cnt]=j-i;
            res+=a[cnt]*a[cnt];cnt++;
            i=j;
        }
        printf("Case #%I64d: ",kcase++);
        if(cnt==1){         //ֻҪһ����ɫ
            printf("%I64d\n",res);continue;
        }
        LL ans=res;
        for(i=0;i<cnt;i++){
            LL t=res;
            if(a[i]==1){        //�������ɢ��ֻ��һ������ı���ʱ��Ӱ���������ߵĿ�
                LL now=a[i];
                t-=a[i]*a[i];
                if(i<cnt-1){
                    now+=a[i+1];
                    t-=a[i+1]*a[i+1];
                }
                if(i){
                    now+=a[i-1];
                    t-=a[i-1]*a[i-1];
                }
                t+=now*now;
                ans=max(ans,t);
            }else{
                if(i){
                    LL temp=res;
                    temp-=a[i]*a[i];
                    temp-=a[i-1]*a[i-1];
                    temp+=(a[i-1]+1)*(a[i-1]+1);
                    temp+=(a[i]-1)*(a[i]-1);
                    ans=max(ans,temp);
                }
                if(i<cnt-1){
                    LL temp=res;
                    temp-=a[i]*a[i];
                    temp-=a[i+1]*a[i+1];
                    temp+=(a[i+1]+1)*(a[i+1]+1);
                    temp+=(a[i]-1)*(a[i]-1);
                    ans=max(ans,temp);
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
