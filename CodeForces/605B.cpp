/****************
*PID:605b div2
*Auth:Jonariguez
*****************
��Kruskal,�ȶԱ�Ȩ����Ȼ��һ��һ��ȡ�����ڵ�ǰȡ���ıߣ�
�����MST�ıߣ���can++��Ȼ��ڵ�can��ڵ�1������ΪMST��һ���֣�
�������MST�ıߣ���Ѹñ�����2~can�Žڵ��е������ڵ㡣����Ȼ����
�ظ�����Ҫnows��nowt��¼��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int n,m;

struct pp{
    int w,id,T;
}s[maxn];

struct ppp{
    int a,b,id;
}res[maxn];

int cmp(const pp &a,const pp &b){
    if(a.w==b.w)
        return a.T>b.T;
    return a.w<b.w;
}

int cmp1(const ppp &a,const ppp &b){
    return a.id<b.id;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m;i++){
            scanf("%d%d",&s[i].w,&s[i].T);
            s[i].id=i;
        }
        sort(s,s+m,cmp);
        int nows=2,nowt=2,can=1,yes=1;
        for(i=0;i<m;i++){
            if(s[i].T){
                res[i].a=1;res[i].b=++can;res[i].id=s[i].id;
            }else {
                if(nowt>=can && nows==nowt){
                    yes=0;break;
                }
                if(nows==nowt){
                    nowt++;nows=2;
                }
                res[i].a=nowt;res[i].b=nows;res[i].id=s[i].id;
                nows++;
            }
        }
        if(yes==0)
            printf("-1\n");
        else {
            sort(res,res+m,cmp1);
            for(i=0;i<m;i++)
                printf("%d %d\n",res[i].a,res[i].b);
        }
    }
    return 0;
}

