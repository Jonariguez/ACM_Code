/****************
*PID:uva10382
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;

struct seg{
    double start,end;
    bool left;
}s[maxn*2];

int cmp(const seg &a,const seg &b){
    return a.start<b.start;
}

int main()
{
    int i,j,n;
    double l,w;
    while(scanf("%d%lf%lf",&n,&l,&w)!=EOF){
        int len=0;
        for(i=0;i<n;i++){
            double p,r;
            scanf("%lf%lf",&p,&r);
            if(r*2<=w) continue;
            double d=sqrt(r*r-w*w/4);
            s[len].start=max((double)0,p-d);
            s[len].end=min(l,p+d);
            len++;
        }
        sort(s,s+len,cmp);
        int res=1,cnt=0;
        double now=0.0,right=0.0;
        if(s[0].start>0){
            printf("-1\n");continue;
        }
        int yes=1;
        now=s[0].end;   //选取第一条
        for(i=0;i<len;){
            j=i;
            while(j<len &&  s[j].start<=now){   //找能和目前选取的这条线段有重叠的线段，并找到往右延伸最远的，即end最大的
                right=max(right,s[j].end);
                j++;
            }
            if(j==i){   //中间断了，则无解
                yes=0;break;
            }
            res++;
            now=right;
            if(right>=l) break; //到头了
            i=j;
        }
        if(yes==0 || now<l)
            printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}
