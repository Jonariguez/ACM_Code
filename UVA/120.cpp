/*
直接模拟，策略则是每次确定一个：第一次找到[cnt,n](cnt初始为1)中编号最
大的那个煎饼的下标(index),然后翻转"index",让它到顶部，然后通过翻转"cnt",
把它翻到最底部，最大号位置确定，cnt++；第二次找[cnt,n]中最大的值，然后
翻转index和cnt与上面类似，直至全部确定
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=33;
int a[maxn],n;

bool check(int s,int &index){   //判断从s开始往上到顶是否有序并找出编号最大的煎饼的下标
    int i,ok=1,maxv=a[s];
    index=s;
    for(i=s+1;i<=n;i++){
        if(maxv<a[i]){
            maxv=a[i];index=i;
        }
        if(a[i]>a[i-1])
            ok=0;
    }
    return ok==1;
}

void flip(int s){       //把[s,n]区间翻转
    for(int i=s;i<=(s+n)/2;i++){
        int t=a[i];
        a[i]=a[n-i+s];a[n-i+s]=t;
    }
}

int main()
{
    int i,j,m,x;
    char c;
    while(scanf("%d",&a[1])!=EOF){
        scanf("%c",&c);
        if(c=='\n'){
            printf("%d\n0\n",a[1]);continue;    //忘了处理一个数的情况，wa了一次
        }
        n=1;
        while(scanf("%d%c",&x,&c)){
            a[++n]=x;
            if(c=='\n') break;
        }
        for(i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
        for(i=1;i<=n/2;i++){
            int t=a[i];
            a[i]=a[n-i+1];a[n-i+1]=t;
        }
        int cnt=0,index;
        while(cnt++!=n){
            if(cnt==n || check(cnt,index)){ //如果只剩最后一个或者上面的全部有序，则不用再翻了
                printf("0\n");break;
            }
            if(index==cnt){     //如果index就在当前位置，就不用翻，接着确定下一个煎饼就行了
                continue;
            }
            if(index!=n){       //不在最上面，就把它翻到最上面
                printf("%d ",index);
                flip(index);
            }
            printf("%d ",cnt);  //然后翻到cnt位置
            flip(cnt);
        }
    }
    return 0;
}
