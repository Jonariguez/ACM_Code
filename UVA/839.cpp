/*
说白了就是考查递归。
我写的和LRJ书的方法没想到会那么相似，说明我跟他
的想法算是一样吧。
再次感叹函数形参的传地址形式，这确实能让程序写
着很舒服。
这个题的总体思想就是：在每一层，递归(如果需要
的话)求解左边left和右边right的总重，然后判断当前
层是否平衡。
这是这个题我写的最初版，并没有很好的简化代码
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

bool yes;
ll sum_left,sum_right;

void dfs(ll &weight){
    ll w1,d1,w2,d2;
    scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
    ll left=0,right=0;
    if(w1 && w2){       //叶子节点就直接判断是否平衡
        left=w1;right=w2;
    }else if(w1==0 && w2){    //如果是左边需要递归，那么右边就是w2，而左边时把sum_left传进去计算即可
        right=w2;
        dfs(left);      //递归得到左边的全部重量，然后判断
    }else if(w2==0 && w1){
        left=w1;
        dfs(right);
    }else if(w1==0 && w2==0){
        dfs(left);
        dfs(right);
    }
    if(left*d1!=right*d2)
        yes=false;
    weight+=left+right; //然后再这层的重量全部回传给weigh
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        yes=true;
        sum_left=sum_right=0;
        ll w1,d1,w2,d2;
        scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
        if(w1 && w2){
            sum_left=w1;
            sum_right=w2;
        }else if(w1==0 && w2){
            sum_right=w2;
            dfs(sum_left);
        }else if(w2==0 && w1){
            sum_left=w1;
            dfs(sum_right);
        }if(w1==0 && w2==0){
            dfs(sum_left);
            dfs(sum_right);
        }
        if(yes && sum_left*d1==sum_right*d2)    //别忘了还有判断yes
            printf("YES\n");
        else
            printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
