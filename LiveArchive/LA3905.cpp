/****************
*PID:LA3905
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-8

const int maxn=100000+10;

struct Event{
    double v;
    bool bLeft;
}s[maxn*2];

int w,h;

int cmp(const Event &x,const Event &y){
    if(fabs(x.v-y.v)<eps)
        return x.bLeft==false;      //����ʱ���v��ȣ�bLeftΪfalse����
    return x.v<y.v;
}

//��ȥ��x��y����ȥ��������ֻҪһ�������ͳ���������Lȡmax��Rȡmin
bool update(int x,int a,int w,double &L,double &R){
    if(a==0){
        if(x<=0 || x>=w) R=L-1;
    }else if(a>0){
        L=max(L,-(double)x/a);
        R=min(R,(double)(w-x)/a);
    }else {
        L=max(L,-(double)(x-w)/a);
        R=min(R,-(double)x/a);
    }
}

int main()
{
    int i,j,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&w,&h);
        scanf("%d",&n);
        int x,y,a,b,tot;
        tot=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&x,&y,&a,&b);
            double L=0,R=1e9;
            update(x,a,w,L,R);
            update(y,b,h,L,R);
            if(L<R){
                s[tot].v=L;s[tot++].bLeft=true;
                s[tot].v=R;s[tot++].bLeft=false;
            }
        }
        sort(s,s+tot,cmp);
        int cnt=0,res=0;
        for(i=0;i<tot;i++){
            if(s[i].bLeft)          //�����bLeftһ��ʼ���ó�int��1��-1�������ж���٣�ֱ����cnt+=bLeft������
                res=max(res,++cnt);
            else cnt--;
        }
        printf("%d\n",res);
    }
    return 0;
}
