/****************
*PID:486c div2
*Auth:Jonariguez
*****************
策略：如果两边的两个字符不一样，只需要挑其中一个即可，
这样省去从这头移动到那头的距离更优。所以只需要处理p所在的
序列的那一半即可（前半部分或者后半部分）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[maxn];
int cnt[maxn];

int main()
{
    int i,j,n,res,p;
    while(scanf("%d%d",&n,&p)!=EOF){
        res=0;
        scanf("%s",str+1);
        memset(cnt,0,sizeof(cnt));
        int s=1,t=n,sum=0;
        while(s<t){
            if(str[s]==str[t]){
                s++;t--;continue;
            }
            if(str[s]<str[t])
                cnt[s]=cnt[t]=min(str[t]-str[s],str[s]+26-str[t]);
            else cnt[s]=cnt[t]=min(str[s]-str[t],str[t]+26-str[s]);
            sum+=cnt[s];
            s++;t--;
        }
        if(sum==0){
            puts("0");continue;
        }
        int l,r;
        if(p<=n/2){
            l=1;r=n/2;
        }else {
            l=n/2+1;r=n;
            if(n&1) l++;
            if(n&1 && p==n/2+1){
                p++;res++;
            }
        }
       // printf("l=%d r=%d\n",l,r);

        while(l<=p){
            if(cnt[l]) break;
            l++;
        }
        if(l<=p){
            while(r>=p){
                if(cnt[r]) break;
                r--;
            }
            if(r>=p){
                for(i=l;i<=r;i++) res+=cnt[i];
                res+=min(p-l,r-p)*2+max(p-l,r-p);
            }else {
                for(i=l;i<=p;i++) res+=cnt[i];
                res+=p-l;
            }
        }else {
            while(r>=p){
                if(cnt[r]) break;
                r--;
            }
            if(r>=p){
                for(i=p;i<=r;i++) res+=cnt[i];
                res+=r-p;//printf("??\n");
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

/*
accdzdcba
*/
