/****************
*PID:496d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int sum[maxn],a[maxn],Petya[maxn],Gena[maxn],P[maxn],G[maxn];

struct pp{
    int ss,tt;
}res[maxn*2];

int cmp(const pp &x,const pp &y){
    if(x.ss==y.ss)
        return x.tt<y.tt;
    return x.ss<y.ss;
}

int main()
{
    int i,j,n,s,t;
    while(scanf("%d",&n)!=EOF){
        int cnt1=0,cnt2=0;
        sum[0]=Petya[0]=Gena[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1){    //Petya[cnt1]=i表示第cnt1次出现1是在i处，P[i]=cnt1表示到i处共出现了cnt1个1
                cnt1++;Petya[cnt1]=i;P[i]=cnt1;G[i]=cnt2; //1
            }else {
                cnt2++;Gena[cnt2]=i;G[i]=cnt2;P[i]=cnt1;  //2
            }
        }
        int k=0;
        if(a[n]==1){    //Petya win
            for(t=1;t<=n;t++){
                int x=t,y=t,p=0,g=0,yes=0;
                while(x<=cnt1){
                    yes=1;
                    if(x==cnt1 && y>cnt2){  //最后一局赢
                        p++;break;
                    }
                    if(y>cnt2){         //只有1，即只有Petya赢
                        p++;x+=t;
                        continue;
                    }
                    if(Petya[x]<Gena[y]){   //Petya先赢够x分
                        p++;y=G[Petya[x]];
                    }else {
                        g++;x=P[Gena[y]];//否则Gena赢
                    }
                    x+=t;y+=t;
                    if(x==cnt1 && y>cnt2){  //最后一局Petya赢
                        p++;break;
                    }
                }
                if(yes==0 && x==cnt1 && y>cnt2) //这是只能一局赢的情况
                    p++;
                if(x==cnt1 && p>g){         //恰好玩到最后一局且Petya赢了
                    res[k].tt=t;res[k++].ss=p;
                }
            }
        }else {             //情况和Petya赢类似且相反
            for(t=1;t<=n;t++){
                int x=t,y=t,p=0,g=0,yes=0;
                while(y<=cnt2){
                    yes=1;
                    if(y==cnt2 && x>cnt1){
                        g++;break;
                    }
                    if(x>cnt1){
                        g++;y+=t;
                        continue;
                    }
                    if(Petya[x]<Gena[y]){   //Gena先赢够x分
                        p++;y=G[Petya[x]];
                    }else {
                        g++;x=P[Gena[y]];
                    }
                    x+=t;y+=t;
                    if(x>cnt1 && y==cnt2){
                        g++;break;
                    }
                }
                if(yes==0 && x==cnt1 && y>cnt2)
                    g++;
                if(y==cnt2 && g>p){
                    res[k].tt=t;res[k++].ss=g;
                }
            }
        }
        printf("%d\n",k);
        sort(res,res+k,cmp);
        for(i=0;i<k;i++)
            printf("%d %d\n",res[i].ss,res[i].tt);
    }
    return 0;
}
