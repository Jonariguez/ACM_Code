/*
һ�仰���ӵ���
һ��ʼ����û������ɢ����ʵ��ɢ����߶�
����������ɢ�������index�е��±�����ʾ��
�����ö˵������ʾ(������poj2528)��
����ɢ����m�����ߣ���ô����m-1�����䣬����
m-1�������Ų�������ʾ�߶Ρ�
��һ�����䳤��index[2]-index[1];
�ڶ������䳤��index[3]-index[2];
���������䳤��index[4]-index[3];
��������
index�б�����������y(y1<=y2<=y3<=y4....ym),
����һ���߶�l�Ǵ�y1��y4�ģ����±��ʾl��[1,4]��    ������
�ö˵������ʾ��l��Խ�˵�һ���ڶ����������䣬
ȡ���˵�����(����һ������)���ʾΪ[1,3]            ������
(y1-y4 -> [1,3],�����ں�����L��Rʱ��R��Ҫ-1��)

֮���Զ˵������ʾ���ԣ����±��ʾ�����Ե�ԭ��
�ǣ��磺
����������[1,4],�ֽ�Ϊ[1,2],[3,4],�����±귨��
��[1,4]��y1-y4,������Ȼ��len=index[y4]-index[y1];
��[1,2]��y1-y2,������Ȼ��len=index[y2]-index[y1];
��[3,4]��y3-y4,��������len=index[y4]-index[y3];
�����ԣ��ֽ��index[y3]-index[y2]��γ���û����
ƾ����ʧ�ˣ������ɸ��׺Ͷ��Ӳ��ȣ���϶��Ͳ����ˡ�

����re(Runtime Error (ACCESS_VIOLATION))����������
�ҵ����鶼���ô󵽱��ˣ�����re���ҵ������Ǳ�����~
ͻȻ���˸����ݣ�����ʱ�����ˣ�
2
1 1 2 2
1 1 2 2
���Լ������ݺ�ó����ۣ�ֻҪ����y����ͶӰֻ��һ����ͬ���߶Σ�
�ͱ����磺
3
1 1 2 2
1 1 3 2
1 1 4 2
������Ϊ��indexȥ�ص�ʱ�򣬰����һ��ֵ©���ˣ�ֱ�ӵ���
�ľ��Ǵ�����m��ֵ���Ǳ���ȷֵС1��������getIndexʱҲ��©
һ��ֵ��
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=110;
int cover[maxn*8];
double sum[maxn*8],index[maxn*2];

struct Line{
    double x,y1,y2; //x��ʾλ�ã�y1��y2��ʾ�߶εĶ˵�
    bool left;
}lines[maxn*4];

int cmp(const Line &a,const Line &b){
    return a.x<b.x;
}

void pushUp(int k,int l,int r){
    if(cover[k])
        sum[k]=index[r+1]-index[l];     //��������˵������ʾ���ķ���
    else if(l==r)
            sum[k]=0;
    else sum[k]=sum[k*2]+sum[k*2+1];
}

void build(int k,int l,int r){
    sum[k]=0;
    cover[k]=0;
    if(l==r)
        return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void Insert(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]++;
        //����ʱcover[k]��Ϊ0������ֻ�������Ϊ0���������
        sum[k]=index[r+1]-index[l];
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,k*2,l,m);
    if(b>m)
        Insert(a,b,k*2+1,m+1,r);
    pushUp(k,l,r);
}

void Delete(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]--;
        if(cover[k]==0)     //ͬInsert��ֻ�账��Ϊ0��ʱ��
            if(l==r) sum[k]=0;
            else sum[k]=sum[k*2]+sum[k*2+1];
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Delete(a,b,k*2,l,m);
    if(b>m)
        Delete(a,b,k*2+1,m+1,r);
    pushUp(k,l,r);
}

int getIndex(double y,int n){
    return (lower_bound(index+1,index+n+1,y)-index);
}

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n) && n){
        int tot=0;
        double x1,x2,y1,y2;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            lines[tot].x=x1;
            lines[tot].y1=y1;
            lines[tot].y2=y2;
            lines[tot].left=true;
            index[tot++]=y1;
            lines[tot].x=x2;
            lines[tot].y1=y1;
            lines[tot].y2=y2;
            lines[tot].left=false;
            index[tot++]=y2;
        }
        sort(lines,lines+tot,cmp);
        sort(index,index+tot);
        int m=0;
        for(i=1;i<tot;i++)
            if(index[i]!=index[i-1])
                index[m++]=index[i-1];
        /*�������ȥ��ʱ��©�����һ��ֵ�Ĵ��룬��ʵif��û��Ҫ��
        if(index[tot-1]!=index[tot-2])
            index[m++]=index[tot-1];*/
        index[m++]=index[tot-1];
        //��index����ת�����±��1��ʼ�ģ��������߶���[1,m]���Ӧ�������
        for(i=m;i>0;i--)
            index[i]=index[i-1];
        index[0]=0;
      //  memset(cover,0,sizeof(cover));
      //  memset(sum,0,sizeof(sum));
        build(1,1,m);
        double res=0;
        for(i=0;i<tot-1;i++){
            int L=getIndex(lines[i].y1,m),R=getIndex(lines[i].y2,m)-1;
            if(lines[i].left)
                Insert(L,R,1,1,m);
            else
                Delete(L,R,1,1,m);
            res+=sum[1]*(lines[i+1].x-lines[i].x);
        }
        printf("Test case #%d\n",kcase++);
        printf("Total explored area: %.2f\n\n",res);
    }
    return 0;
}

/*
2
1 1 2 2
1 1 2 2
*/
