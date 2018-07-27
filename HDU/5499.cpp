/****************
*PID:hdu5499
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct pp{
    int sex;
    double r[3],sum;
    char name[33];
}s[110],t[110];

int cmp(const pp &x,const pp &y){
    return x.sum>y.sum;
}

int res[110];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        double r1,r2;
        r1=r2=-1.0;
        int yes=0;
        char se[10];
        for(i=0;i<n;i++){
            scanf("%s%s%lf%lf",s[i].name,se,&s[i].r[1],&s[i].r[2]);
            if(se[0]=='f'){
                s[i].sex=1;
                yes=1;
            }
            else s[i].sex=0;
            r1=max(r1,s[i].r[1]);
            r2=max(r2,s[i].r[2]);
        }
        for(i=0;i<n;i++){
            s[i].r[1]=s[i].r[1]*(300/r1);
            s[i].r[2]=s[i].r[2]*(300/r2);
            s[i].sum=s[i].r[1]*0.3+s[i].r[2]*0.7;
        }
        sort(s,s+n,cmp);
        if(yes){
            int p=0;
            for(;p<n;p++)
                if(s[p].sex==1) break;
            t[0]=s[p];
            int tot=1;
            int cnt=m-1;
            for(i=0;i<n && cnt;i++){
                if(i==p) continue;
                t[tot++]=s[i];cnt--;
            }
            sort(t,t+m,cmp);
        }else {
            for(i=0;i<m;i++)
                t[i]=s[i];
        }
        printf("The member list of Shandong team is as follows:\n");
        for(i=0;i<m;i++)
            printf("%s\n",t[i].name);
    }
    return 0;
}
