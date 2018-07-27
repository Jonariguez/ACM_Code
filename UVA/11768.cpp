/****************
*PID:uva11768
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

void Exgcd(LL a,LL b,LL &d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

int main()
{
    int n,m,T;
    double X1,Y1,X2,Y2;
    scanf("%d",&T);
    while(T--){
        LL x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
        x1=((X1+0.05)*10);     //要加上0.05，避免精度问题
        y1=((0.05+Y1)*10);
        x2=((0.05+X2)*10);
        y2=((0.05+Y2)*10);
        if(x1==x2 && x1%10==0){
            if(y1>y2) swap(y1,y2);
            double k1=floor(1.0*y1/10),k2=floor(1.0*y2/10);
            int res=k2-k1;
            if(y1%10==0) res++;
            printf("%d\n",res);
            continue;
        }else if(x1==x2){
            printf("0\n");continue;
        }
        if(y1==y2 && y1%10==0){
            if(x1>x2) swap(x1,x2);
            double k1=floor(1.0*x1/10),k2=floor(1.0*x2/10);
            int res=k2-k1;
            if(x1%10==0) res++;
            printf("%d\n",res);
            continue;
        }else if(y1==y2){
            printf("0\n");continue;
        }
        LL a=(y2-y1)*10;
        LL b=(x1-x2)*10;
        LL c=x1*y2-x2*y1;    //之所以*10，是因为这样求出来的解是10的倍数，这样的运算是在全是10的倍数的数上进行的运算。
        LL d,x,y;
        Exgcd(a,b,d,x,y);
        if(c%d!=0){
            printf("0\n");continue;
        }
       // a/=d;b/=d;c/=d;x*=c;y*=c;
       // LL t=b/d;
       // LL tt=c/d;
        b/=d;
        c/=d;
        x*=c;
       // x=((x*tt)%t+t)%t;
        double K1=1.0*(x1-10*x)/(10*b),K2=1.0*(x2-10*x)/(10*b);
        LL k1,k2;
        if(K1>K2){
            k1=ceil(K1);k2=floor(K2);
        }else {
            k1=ceil(K2);k2=floor(K1);
        }//printf("??\n");
        int res=0;
        for(LL i=k2;i<=k1;i++){
            LL temp=10*(x+i*b);
            if(temp<=max(x1,x2) && temp>=min(x1,x2)) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}

