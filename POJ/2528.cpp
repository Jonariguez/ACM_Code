/*
初识线段树
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int x[maxn],y[maxn];

//线段的个数最大值为maxn。而一个线段两个点，如果离散地挤满的话，也得大概需要2*maxn的点，所以这里maxn要乘大一点
int cover[maxn*8];

void pushDown(int k){
    if(cover[k]>=0){
        cover[k*2]=cover[k*2+1]=cover[k];
        cover[k]=-1;
    }
}

void Insert(int a,int b,int c,int k,int l,int r){
    if(cover[k]==c) return ;
    if(a<=l && b>=r){           //这里区间判断不能是a==l && b==r ，因为要求要包含不是相等
        cover[k]=c;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,c,k*2,l,m);
    if(b>m)
        Insert(a,b,c,k*2+1,m+1,r);
}

int cnt[maxn];

void query(int k,int l,int r){
    if(cover[k]>=0){
        cnt[cover[k]]=1;return ;
    }
    if(l==r) return ;
    pushDown(k);
    int m=(l+r)/2;
    query(k*2,l,m);
    query(k*2+1,m+1,r);
}

unsigned short mark[10000002];  //原来unsigned short是16位，可以开很大的.其实用bool（8位）可以开更大的，
                                //但是此题后面还有mark[temp[i]]=i+1;，所以不能是bool的
int temp[maxn*2];

int main()
{
    int i,j,k,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        //离散化
        memset(mark,0,sizeof(mark));
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(mark[x[i]]==0){
                mark[x[i]]=1;
                temp[tot++]=x[i];
            }
            if(mark[y[i]]==0){
                mark[y[i]]=1;
                temp[tot++]=y[i];
            }
        }
        sort(temp,temp+tot);
        for(i=0;i<tot;i++)
            mark[temp[i]]=i+1;
        for(i=0;i<n;i++)
            Insert(mark[x[i]],mark[y[i]],i,1,1,tot);    //mark[x[i]]代表线段的左端点离散化后的编号，较上次提交AC代码改动了
        memset(cnt,0,sizeof(cnt));
        query(1,1,tot);
        int sum=0;
        for(i=0;i<=n;i++)       //注意这里是循环到n不是tot
            sum+=cnt[i];
        printf("%d\n",sum);
    }
    return 0;
}

