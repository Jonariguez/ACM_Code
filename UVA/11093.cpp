#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=100000+10;
ll p[maxn],q[maxn];

int main()
{
    int start,i,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&p[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&q[i]);
        start=0;
        int flag=0;
        while(true){
            int cnt=0;
            ll sum=0;
            for(i=start;;i=(i+1)%n){    //从start开始
                if(sum+p[i]>=q[i]){
                    sum+=p[i]-q[i];
                    if(++cnt==n){       //走了一圈了就成功了
                        flag=1;break;
                    }
                }else break;
            }
            if(flag==1) break;      //成功就提前退出
            if(i<start) break;      //这是说明start到n都没有中断，即i在从0向start走的过程中中断，这时是not
            start=i+1;
        }
        printf("Case %d: ",kcase++);
        if(flag==0)
            printf("Not possible\n");
        else
            printf("Possible from station %d\n",start+1);
    }
    return 0;
}



