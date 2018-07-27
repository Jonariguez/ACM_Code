/*
ID:Jonairugez7
PROG:milk2
LANG:C++
*/

/*��һ��
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
int vis[maxn];

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    int x,y;
    memset(vis,0,sizeof(vis));
    int maxv=-1,minv=1000006;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(maxv<y) maxv=y;
        if(minv>x) minv=x;
        vis[x]++;vis[y]--;      //ע�����������Ŀ����������vis[y]--,����vis[y+1]--
    }
    for(i=1;i<=maxv;i++)
        vis[i]+=vis[i-1];
    int ans1=-1,ans2=-1,zero=0,nzero=0;
    for(i=minv;i<=maxv;i++){        //һ��Ҫע�������minv��ʼ��������0
        if(vis[i]==0){
            zero++;
            ans1=Max(ans1,nzero);
            nzero=0;
        }
        else {
            nzero++;
            ans2=Max(ans2,zero);
            zero=0;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

/*������
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
int vis[maxn];

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    int x,y;
    memset(vis,0,sizeof(vis));
    int maxv=-1,minv=1000006;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(maxv<y) maxv=y;
        if(minv>x) minv=x;
        vis[x]++;vis[y]--;      //ע�����������Ŀ����������vis[y]--,����vis[y+1]--
    }
    //�÷�������ȥ�������ɨ��
//    for(i=1;i<=maxv;i++)
//        vis[i]+=vis[i-1];
    int ans1=0,ans2=0,sum=0,mark;
    mark=minv;
    bool free=false;
    //sum֮��������������ʣ���Ϊ�����������ʱ��ֻҪǰ����һ��vis[x]+1���������һ��vis[y]-1�����Ӧ
    //Ҳ������˲������sum=0���������Ϊ��-1����ô֮ǰ����+1��������maxv<=i<=maxv����i֮ǰ������+1�Ĵ���������-1�Ĵ���
    for(i=minv;i<=maxv;i++){
        sum+=vis[i];            //���sum==0,��ʾvis[i]λ��0������û��ιţ(��vis[i]��һ����Ϊ0)
                                //���sum!=0,��ʾλ�ڷ�0������ʱ����ι��(������һ����ιţ,ͬʱvis[i]Ҳ��һ����Ϊ0)
        if(sum==0 && free==false){
            if(ans1<i-mark) ans1=i-mark;
            mark=i;
            free=true;      //��������ιţ��
        }
        if(sum!=0 && free==true){
            if(ans2<i-mark) ans2=i-mark;
            mark=i;
            free=false;     //��������ιţ��
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

/*������
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;

struct pp
{
    int b,e;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.b==y.b) return x.e<y.e;
    return x.b<y.b;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].b,&s[i].e);
    if(n==1){
        printf("%d 0\n",s[0].e-s[0].b);
        return 0;
    }
    sort(s,s+n,cmp);
    int ans1=0,ans2=0,f=s[0].b,t=s[0].e;      //ans1��ans2�ĳ�ֵӦ��Ϊ0��������Ϊ-1����Ϊ�������Ĵ���
    for(i=1;i<n;i++){
        if(t>=s[i].b){
            t=max(t,s[i].e);
        }
        else {
            ans1=max(ans1,t-f);     //ans1ҲҪ��������£������������if��
            ans2=max(ans2,s[i].b-t);
            f=s[i].b,t=s[i].e;
        }
    }
    ans1=max(ans1,t-f);         //�������һ����һֱ��ͷ�ɵ�β�����
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

