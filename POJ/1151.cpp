/*
一句话，坑爹。
一开始还是没理解好离散，其实离散后的线段
并不是用离散后的数组index中的下标来表示，
而是用端点区间表示(类似于poj2528)。
即离散后有m个横线，那么是有m-1个区间，将这
m-1个区间标号并用来表示线段。
第一个区间长：index[2]-index[1];
第二个区间长：index[3]-index[2];
第三个区间长：index[4]-index[3];
…………
index中保存的是升序的y(y1<=y2<=y3<=y4....ym),
比如一条线段l是从y1到y4的，用下标表示l是[1,4]，    ——错
用端点区间表示，l跨越了第一、第二、第三区间，
取两端的区间(即第一、第三)则表示为[1,3]            ——对
(y1-y4 -> [1,3],所以在后面求L，R时，R是要-1的)

之所以端点区间表示法对，而下标表示法不对的原因
是，如：
假设有区间[1,4],分解为[1,2],[3,4],若用下标法，
则[1,4]是y1-y4,长度自然是len=index[y4]-index[y1];
则[1,2]是y1-y2,长度自然是len=index[y2]-index[y1];
另[3,4]是y3-y4,长度则是len=index[y4]-index[y3];
很明显，分解后index[y3]-index[y2]这段长度没有了
凭空消失了，这就造成父亲和儿子不等，这肯定就不对了。

这题re(Runtime Error (ACCESS_VIOLATION))到死！！！
我的数组都开得大到爆了，还是re，我的内心是崩溃的~
突然试了个数据，运行时报错了：
2
1 1 2 2
1 1 2 2
多试几组数据后得出结论，只要是在y轴上投影只有一条相同的线段，
就报错，如：
3
1 1 2 2
1 1 3 2
1 1 4 2
就是因为在index去重的时候，把最后一个值漏掉了，直接导致
的就是代码中m的值都是比正确值小1，并且在getIndex时也会漏
一个值。
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
    double x,y1,y2; //x表示位置，y1，y2表示线段的端点
    bool left;
}lines[maxn*4];

int cmp(const Line &a,const Line &b){
    return a.x<b.x;
}

void pushUp(int k,int l,int r){
    if(cover[k])
        sum[k]=index[r+1]-index[l];     //基于上面端点区间表示法的分析
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
        //插入时cover[k]不为0，所以只需出来不为0的情况即可
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
        if(cover[k]==0)     //同Insert，只需处理为0的时候
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
        /*下面就是去重时会漏掉最后一个值的代码，其实if是没必要的
        if(index[tot-1]!=index[tot-2])
            index[m++]=index[tot-1];*/
        index[m++]=index[tot-1];
        //将index数组转换成下标从1开始的，这样与线段树[1,m]想对应，好理解
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
