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
            if(a[i]==1){    //Petya[cnt1]=i��ʾ��cnt1�γ���1����i����P[i]=cnt1��ʾ��i����������cnt1��1
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
                    if(x==cnt1 && y>cnt2){  //���һ��Ӯ
                        p++;break;
                    }
                    if(y>cnt2){         //ֻ��1����ֻ��PetyaӮ
                        p++;x+=t;
                        continue;
                    }
                    if(Petya[x]<Gena[y]){   //Petya��Ӯ��x��
                        p++;y=G[Petya[x]];
                    }else {
                        g++;x=P[Gena[y]];//����GenaӮ
                    }
                    x+=t;y+=t;
                    if(x==cnt1 && y>cnt2){  //���һ��PetyaӮ
                        p++;break;
                    }
                }
                if(yes==0 && x==cnt1 && y>cnt2) //����ֻ��һ��Ӯ�����
                    p++;
                if(x==cnt1 && p>g){         //ǡ���浽���һ����PetyaӮ��
                    res[k].tt=t;res[k++].ss=p;
                }
            }
        }else {             //�����PetyaӮ�������෴
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
                    if(Petya[x]<Gena[y]){   //Gena��Ӯ��x��
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
