/****************
*PID:uva1614
*Auth:Jonariguez
*****************
��Ϊ1<=a[i]<=i,������ѧ���ɷ�֤��:��a[1]-a[i]�Ĳ��ֻ�ȫ
��Ԫ��ͨ����ͣ�һ�����Դճ�1~sum[i]��ÿ��������sum[i]��ǰ i ��Ԫ�صĺͣ�.
������Ԫ�صĺ�Ϊsum��(sumΪ���޽�)ֻ��Ҫ�Ӵ�С�����sum/2���ɣ�һ·̰��
һ���н⡣
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int a[maxn],sign[maxn],id[maxn];
ll sum;

//��a[i]�Ĵ�С������id����
int cmp(int x,int y){
    return a[x]<a[y];
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            id[i]=i;
        }
        if(sum&1){
            printf("No\n");
            continue;
        }
        sum/=2;
        sort(id+1,id+n+1,cmp);
        sort(a+1,a+n+1);
        fill(sign,sign+n+1,-1);
        for(i=n;i>=1;i--){
            if(sum<a[i])
                sign[id[i]]=1;
            else
                sum-=a[i];
        }
        printf("Yes\n");
        for(i=1;i<=n;i++)
            printf("%d%c",sign[i],i==n?'\n':' ');
    }
    return 0;
}

