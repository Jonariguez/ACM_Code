/****************
*PID:uva11536
*Auth:Jonariguez
*****************
��ȡ
������Բ���map��ֱ���ø�vis������У������ʡʱ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn],M,n,k;
map<int,int> cnt;

int main()
{
    int i,j,s,t,res,T,kcase=1;
    scanf("%d",&T);
    a[0]=1;a[1]=2;a[2]=3;
    while(T--){
        scanf("%d%d%d",&n,&M,&k);
        for(i=3;i<n;i++)
            a[i]=(a[i-1]+a[i-2]+a[i-3])%M+1;
        s=t=0;res=n+1;
        int sum=0,yes=0;
        cnt.clear();
        while(t<=n){
            while(t<n && sum<k){
                if(cnt[a[t]]==0 && a[t]<=k) //����һ����Ҫ��cnt.count(a[t])==0!!!!!!
                    sum++;
                cnt[a[t]]++;t++;
            }
            if(sum<k) break;
            res=min(res,t-s);
            yes=1;
            if(--cnt[a[s]]==0 && a[s]<=k)  //��Ҫд��if(a[s]<=k&&--cnt[a[s]]==0) ��Ϊ�����Ǳ���ִ�еģ��������·
                sum--;
            s++;
        }
        printf("Case %d: ",kcase++);
        if(yes==0)
            printf("sequence nai\n");
        else
            printf("%d\n",res);
    }
    return 0;
}

