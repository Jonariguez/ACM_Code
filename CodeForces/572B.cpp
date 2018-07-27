/****************
*PID:cf572B
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

struct order{
    int p,q;
    order(int p=0,int q=0):p(p),q(q){}
}s[maxn],b[maxn];

int cmpd(const order &x,const order &y){
    if(x.p==y.p)
        return x.q<y.q;
    return x.p>y.p;
}

int cmpi(const order &x,const order &y){
    if(x.p==y.p)
        return x.q<y.q;
    return x.p<y.p;
}

int main()
{
    int i,j,n,S;
    while(scanf("%d%d",&n,&S)!=EOF){
        char ch[3];
        int p,q,cnts=0,cntb=0;
        for(i=0;i<n;i++){
            scanf("%s%d%d",ch,&p,&q);
            if(ch[0]=='B'){
                b[cntb]=order(p,q);
                cntb++;
            }else {
                s[cnts]=order(p,q);
                cnts++;
            }
        }
        sort(b,b+cntb,cmpd);
        sort(s,s+cnts,cmpi);
        int tb=0,ts=0;
        for(i=1;i<cntb;i++){
            if(b[i].p==b[i-1].p){
                b[tb].p=b[i].p;b[tb].q+=b[i].q;
            }else {
                b[++tb].p=b[i].p;b[tb].q=b[i].q;
            }
        }
     //   printf("tb=%d\n",tb);
     //   printf("cnts=%d\n",cnts);
        for(i=1;i<cnts;i++){
            if(s[i].p==s[i-1].p){
                s[ts].p=s[i].p;s[ts].q+=s[i].q;
            }else {
                s[++ts].p=s[i].p;s[ts].q=s[i].q;
            }
        }
    //    printf("ts=%d\n",ts);
        sort(s,s+ts+1,cmpi);        //注意输出s时，是把前S小降序输出
        sort(b,b+tb+1,cmpd);
        int tot=min(ts+1,S);
        if(cnts!=0)
            for(i=tot-1;i>=0;i--)
                printf("S %d %d\n",s[i].p,s[i].q);
        tot=min(tb+1,S);
        if(cntb!=0)
            for(i=0;i<tot;i++)
                printf("B %d %d\n",b[i].p,b[i].q);
    }
    return 0;
}
