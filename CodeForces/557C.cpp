/*
����ö�ٸ������ȣ�
���賤��Ϊa������y������ô����������Ҫ����
һ�����ȴ���a�ģ�ȫ������
��������С��a�ģ�������x������Ҫ����x-y+1����
�ÿ���(��d��С��)��

��һ�����������Ԥ����ǰ׺�ͣ�O(1)��ʱ��������ĵ�d
�ڶ����������Ϊd�ķ�ΧС���������±귨��ʾ����
small[i]=u����ʾ����Ϊi������u����ֻ��Ҫi��1��200
����x-y+1���Ϳ����ˡ�Ȼ��ʱʱ����small����
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
const int maxd=202;
int vis[maxn],a[maxn],l[maxn],sum[maxn],cnt[maxn],small[maxd],n;

struct pp{
    int l,d;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.l==y.l) return x.d<y.d;
    return x.l<y.l;
}

int getBig(int x){
    return sum[n-1]-sum[vis[x]];
}

int getSma(int x){
    int i,res=0;
    for(i=1;i<=200;i++){
        if(x>=small[i]){
            res+=small[i]*i;
            x-=small[i];
        }
        else {
            res+=i*x;break;
        }
    }
    return res;
}


int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        memset(cnt,0,sizeof(cnt));
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d",&s[i].l);
            if(cnt[s[i].l]==0)
                a[tot++]=s[i].l;
            cnt[s[i].l]++;
        }
        for(i=0;i<n;i++)
            scanf("%d",&s[i].d);
        sort(s,s+n,cmp);
        sum[0]=s[i].d;
        for(i=1;i<n;i++){
            sum[i]=sum[i-1]+s[i].d;
            if(s[i].l!=s[i-1].l)
                vis[s[i-1].l]=i-1;
        }
        vis[s[n-1].l]=n-1;
        int cur,res=20000001;
        for(i=0;i<n;i++){
            if(i==0 || s[i].l!=s[i-1].l){
                int y=cnt[s[i].l],x=i;
                int t=getBig(s[i].l);
                if(x>=y)       //ȥ��x-y+1��
                    t+=getSma(x-y+1);
                res=min(res,t);
            }
            small[s[i].d]++;
        }
        printf("%d\n",res);
    }
    return 0;
}

