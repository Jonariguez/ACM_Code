/*
单调队列(deque)
维护最小值qmin中：从左到右单调递增
维护最大值qmax中：从左到右单调递减
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn],b[maxn],c[maxn];

/*
由于窗口的滑动，每次要还要判断队列中最左边(即队列头部)的元素是否
会因为滑动而被删掉，那么我们必须要知道最左边元素在原数组中的位置
(即下标),所以我们在deque队列中保存的每个元素的下标，而非元素的值
*/

int deq1[maxn*2],deq2[maxn*2];

//向单调队列里添加元素时，利用其单调性二分，这样才不超时
int B_search1(int s,int t,int x){
    int l=s,r=t;
    while(l<r){
        int m=(l+r)/2;
        if(a[deq1[m]]>=x)
            r=m;
        else
            l=m+1;
    }
    return r;
}

int B_search2(int s,int t,int x){
    int l=s,r=t;
    while(l<r){
        int m=(l+r)/2;
        if(a[deq2[m]]>x)
            l=m+1;
        else
            r=m;
    }
    return r;
}

int main()
{
    int i,j,k,n,s1,t1,s2,t2;
    scanf("%d%d",&n,&k);
 //   for(i=0;i<n;i++)

    s1=t1=s2=t2=0;
    int f=0;
    for(i=0;i<n;i++){
      //  while(s1<t1 && a[deq1[t1-1]]>=a[i])      //注意：单调队列每次的比较插入是从后往前的
      //      t1--;
        scanf("%d",&a[i]);
        if(s1<t1)
            t1=B_search1(s1,t1,a[i]);
        deq1[t1++]=i;
        if(i-k+1>=0){       //如果i<k,则说明现在窗口中还不够k个数需要接着添加，够了的话就执行该if
          //  b[i-k+1]=a[deq1[s1]];
            if(f)
                printf(" ");
            f++;
            printf("%d",a[deq1[s1]]);
            if(deq1[s1]==i-k+1)           //恰好因为窗口的滑动而删掉队列头部的元素
                s1++;
        }
  //      while(s2<t2 && a[deq2[t2-1]]<=a[i])
   //         t2--;

    }
    printf("\n");
    f=0;
    for(i=0;i<n;i++){
            if(s2<t2)
            t2=B_search2(s2,t2,a[i]);
        deq2[t2++]=i;
        if(i-k+1>=0){
            if(f)
                printf(" ");
            f++;
            printf("%d",a[deq2[s2]]);
            if(deq2[s2]==i-k+1)
                s2++;
        }
    }
    printf("\n");
    return 0;
}
