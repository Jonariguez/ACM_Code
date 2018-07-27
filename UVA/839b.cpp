/*
说白了就是考查递归。
我写的和LRJ书的方法没想到会那么相似，说明我跟他
的想法算是一样吧。
再次感叹函数形参的传地址形式，这确实能让程序写
着很舒服。
这个题的总体思想就是：在每一层，递归(如果需要
的话)求解左边left和右边right的总重，然后判断当前
层是否平衡。
(既然思想和代码都差不多，就根据他的简化一个代码)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

bool yes;
ll sum_left,sum_right;

void solve(ll &weight){
    ll w1,d1,w2,d2;
    scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
    if(!w1) solve(w1);    //哪里有子树就往哪里递归求一边的总重量
    if(!w2) solve(w2);
    if(w1*d1!=w2*d2)
        yes=false;
    weight+=w1+w2; //然后再这层的重量全部回传给weigh
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        yes=true;
        ll W;
        solve(W);       //其实这个W是没用的，定义它也只是为了调用solve函数有个“形参”可传
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
